from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
df = pd.read_csv('face.csv')

Classes = df['target']
df.drop(columns=['target'], inplace=True)


def PCA(X):

    mean = np.average(X, axis=0)

    Z = (X - mean) / (np.max(X, axis=0) - np.min(X, axis=0))
    cov_mat = np.dot(Z.T, Z)

    e_val, e_vec = np.linalg.eigh(cov_mat)
    print('Eigen value shape :', e_val.shape,
          'Eigen vector shape :', e_vec.shape)

    sorted_e_val = np.flip(np.sort(e_val))
    sorted_e_vec = e_vec.copy()
    dummy = 0

    for val in sorted_e_val:
        ind = np.argmax(e_val == val * 1)
        sorted_e_vec[:, dummy] = e_vec[:, ind]
        dummy += 1

    variances = []
    for i in sorted_e_val:
        variances.append(i/np.sum(sorted_e_val))

    variances.sort()
    d_dash = 0
    var = 0

    for i in variances[::-1]:
        if (var < 0.95):
            var = var + i
            d_dash = d_dash + 1
        else:
            break

    plt.figure(figsize=(55, 13))
    plt.bar([str(i + 1) for i in range(len(e_val))], np.sort(e_val))
    plt.show()

    Z_star = np.dot(Z, sorted_e_vec)

    return Z_star[:, :d_dash]


PC_X = PCA(df)
print(PC_X.shape)

X_train, X_test, y_train, y_test = train_test_split(
    PC_X, Classes, test_size=0.2, stratify=Classes, random_state=39)

model = GaussianNB()
model.fit(X_train, y_train)
predictions = model.predict(X_test)
y_test = list(y_test)
accurate = list(y_test == predictions)
print("Accuracy =", (accurate.count(True)/len(accurate))*100, "%")
