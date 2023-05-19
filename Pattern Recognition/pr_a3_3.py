from sklearn.metrics import confusion_matrix
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


df = pd.read_csv('gender.csv')
df.head(3)

features = df.drop(['Unnamed: 0', 'Unnamed: 1'], axis=1)
X = features
X.head(3)


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

class1 = PC_X[:len(df.loc[df['Unnamed: 1'] == 'male'])]
class2 = PC_X[len(df.loc[df['Unnamed: 1'] == 'male']):]

train1 = class1[10:]
test1 = class1[:10]

train2 = class2[10:]
test2 = class2[:10]

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

maleTrain = df[df['Unnamed: 1'] == 'male'].iloc[10:, 2:]
femaleTrain = df[df['Unnamed: 1'] == 'female'].iloc[10:, 2:]

maleTest = df[df['Unnamed: 1'] == 'male'].iloc[:10, 2:]
femaleTest = df[df['Unnamed: 1'] == 'female'].iloc[:10, 2:]

meanMale = np.array([np.mean(maleTrain[str(i)]) for i in range(128)])
meanFemale = np.array([np.mean(femaleTrain[str(i)]) for i in range(128)])
mean = [np.mean(df[str(i)]) for i in range(128)]


def ScatterClass(mat, mean):
    S = np.matrix(np.zeros((len(mat.columns), len(mat.columns))))
    for i in range(len(mat)):
        z = np.matrix(np.array(mat.iloc[i, :])-mean)
        S = S + np.matmul(z.T, z)
    return S


S1 = ScatterClass(maleTrain, meanMale)
S2 = ScatterClass(femaleTrain, meanFemale)

Sw = S1+S2
Swinv = np.linalg.inv(Sw)
meandiff = np.matrix(meanMale - meanFemale).T
W = Swinv*meandiff


points = [float(np.dot(df.iloc[i, 2:], W)) for i in range(len(df))]

MaleMean = np.mean(points[10:399])
FemaleMean = np.mean(points[410:])

pred_male = [abs(i-MaleMean) < abs(i-FemaleMean) for i in points[:10]]
pred_female = [abs(i-MaleMean) > abs(i-FemaleMean) for i in points[400:410]]


TruePred = ['Male']*10 + ['Female']*10
PCApred = ['Male' if i else 'Female' for i in pred_test1] + \
    ['Female' if i else 'Male' for i in pred_test2]
LDApred = ['Male' if i else 'Female' for i in pred_male] + \
    ['Female' if i else 'Male' for i in pred_female]

ax = plt.subplot()
sns.heatmap(confusion_matrix(TruePred, PCApred), annot=True, ax=ax)
ax.set_xlabel('Predicted labels')
ax.set_ylabel('True labels')
ax.set_title('Confusion Matrix of PCA')
ax.xaxis.set_ticklabels(["Female", "Male"])
ax.yaxis.set_ticklabels(["Female", "Male"])
plt.show()


ax = plt.subplot()
sns.heatmap(confusion_matrix(TruePred, LDApred), annot=True, ax=ax)
ax.set_xlabel('Predicted labels')
ax.set_ylabel('True labels')
ax.set_title('Confusion Matrix of LDA')
ax.xaxis.set_ticklabels(["Female", "Male"])
ax.yaxis.set_ticklabels(["Female", "Male"])
plt.show()
