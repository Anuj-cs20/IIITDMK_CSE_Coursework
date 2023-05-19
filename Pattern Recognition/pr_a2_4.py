# Anuj.K
# CS20B1100

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math

df = pd.read_csv("Iris.csv")
df.drop(columns=['Id', 'Species'], axis=1, inplace=True)
s_train = df[:40]
s_test = df[40:50]
v_train = df[50:90]
v_test = df[90:100]
vc_train = df[100:140]
vc_test = df[140:150]

m1 = s_train.mean()
m2 = v_train.mean()
m3 = vc_train.mean()
c1 = np.cov(s_train.T)
c2 = np.cov(v_train.T)
c3 = np.cov(vc_train.T)

TrueResults = 0
for i in range(len(s_test)):
    x = s_test.iloc[i]
    x = np.array(x)
    p1 = ((1/np.linalg.det(c1))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m1).T, np.matmul(np.linalg.inv(c1), (x-m1))))
    p2 = ((1/np.linalg.det(c2))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m2).T, np.matmul(np.linalg.inv(c2), (x-m2))))
    p3 = ((1/np.linalg.det(c3))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m3).T, np.matmul(np.linalg.inv(c3), (x-m3))))
    if (p1 > p2 and p1 > p3):
        TrueResults += 1

for i in range(len(v_test)):
    x = v_test.iloc[i]
    x = np.array(x)
    p1 = ((1/np.linalg.det(c1))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m1).T, np.matmul(np.linalg.inv(c1), (x-m1))))
    p2 = ((1/np.linalg.det(c2))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m2).T, np.matmul(np.linalg.inv(c2), (x-m2))))
    p3 = ((1/np.linalg.det(c3))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m3).T, np.matmul(np.linalg.inv(c3), (x-m3))))
    if (p2 > p1 and p2 > p3):
        TrueResults += 1

for i in range(len(vc_test)):
    x = vc_test.iloc[i]
    x = np.array(x)
    p1 = ((1/np.linalg.det(c1))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m1).T, np.matmul(np.linalg.inv(c1), (x-m1))))
    p2 = ((1/np.linalg.det(c2))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m2).T, np.matmul(np.linalg.inv(c2), (x-m2))))
    p3 = ((1/np.linalg.det(c3))**(1/2))*math.exp(-0.5 *
                                                 np.matmul((x-m3).T, np.matmul(np.linalg.inv(c3), (x-m3))))
    if (p3 > p2 and p3 > p1):
        TrueResults += 1

print("The accuracy of the model is:", (TrueResults/30)*100, "%")
