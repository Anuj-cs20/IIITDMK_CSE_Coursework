import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("gender.csv")

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
colours = [len(df.iloc[i, 1]) for i in range(len(df))]

plt.figure(figsize=(6, 6))
plt.scatter(range(389), points[10:399], c='yellow')
plt.scatter(range(390), points[410:], c='green')

plt.scatter(range(0, 400, 40), points[:10], c='blue')
plt.scatter(range(0, 400, 40), points[400:410], c='red')
plt.legend(['MaleTrain', 'FemaleTrain', 'MaleTest', 'FemaleTest'],
           loc='upper right', bbox_to_anchor=(1.35, 1))
plt.show()

MaleMean = np.mean(points[10:399])
FemaleMean = np.mean(points[410:])

pred_male = [abs(i-MaleMean) < abs(i-FemaleMean) for i in points[:10]]
pred_female = [abs(i-MaleMean) > abs(i-FemaleMean) for i in points[400:410]]

print("Predictions for the male test points:\n")
[print("The predition is", i) for i in pred_male]
print("-"*80, "\n")
print("Predictions for the female test points:\n")
[print("The predition is", i) for i in pred_female]
print()

Results = list(pred_male)+list(pred_female)
plt.bar(["Correct", "Wrong"], [Results.count(1), Results.count(0)])

accuracy = Results.count(1)/len(Results)
print("Accuracy is:", accuracy*100, "%")
