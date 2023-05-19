import pandas as pd
import numpy as np
from matplotlib import pyplot as plt

df = pd.read_csv('gender.csv')
features = df.drop(['Unnamed: 0', 'Unnamed: 1'], axis=1)
X = features


def PCA(X):
    mean = np.average(X, axis=0)

    Z = (X - mean) / (np.max(X, axis=0) - np.min(X, axis=0))
    cov_mat = np.dot(Z.T, Z)

    e_val, e_vec = np.linalg.eig(cov_mat)
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


PC_X = PCA(X)
print(PC_X.shape)

class1 = PC_X[:len(df.loc[df['Unnamed: 1'] == 'male'])]
class2 = PC_X[len(df.loc[df['Unnamed: 1'] == 'male']):]

train1 = class1[10:]
test1 = class1[:10]

train2 = class2[10:]
test2 = class2[:10]

plt.figure(figsize=(6, 6))

plt.scatter(train1[:, 0], train1[:, 1])
plt.scatter(train2[:, 0], train2[:, 1])

plt.scatter(test2[:, 0], test2[:, 1])
plt.scatter(test1[:, 0], test1[:, 1])

plt.legend(['MaleTrain', 'FemaleTrain', 'FemaleTest', 'MaleTest'],
           loc='upper right', bbox_to_anchor=(1.35, 1))
plt.show()

print('Predictions for the male test points:\n')

pred_test1 = []

for samp in test1:

    pred_test1.append(np.sqrt(np.sum(np.square(train1 - samp)))
                      < np.sqrt(np.sum(np.square(train2 - samp))))
    print('The predition is', np.sqrt(np.sum(np.square(train1 - samp)))
          < np.sqrt(np.sum(np.square(train2 - samp))))

pred_test1 = np.stack(pred_test1) * 1

print('\n-------------------')
print('\nPredictions for the female test points:\n')

pred_test2 = []

for samp in test2:
    pred_test2.append(np.sqrt(np.sum(np.square(train1 - samp)))
                      > np.sqrt(np.sum(np.square(train2 - samp))))
    print('The predition is', np.sqrt(np.sum(np.square(train1 - samp)))
          > np.sqrt(np.sum(np.square(train2 - samp))))

pred_test2 = np.stack(pred_test2) * 1

Results = pred_test1+pred_test2

Results = list(pred_test1)+list(pred_test2)
plt.bar(["Correct", "Wrong"], [Results.count(1), Results.count(0)])

accuracy = Results.count(1)/len(Results)
print("Accuracy is:", accuracy*100, "%")
