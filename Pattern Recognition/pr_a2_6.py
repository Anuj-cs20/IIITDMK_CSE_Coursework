import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 
import math

df=pd.read_csv("face feature vectors.csv")
df.drop(df.columns[[0,1]],axis=1,inplace=True)
male_Train=df[5:400]
male_test=df[:5]
female_train=df[405:800]
female_test=df[400:405]

mean1=male_Train.mean()
mean2=female_train.mean()
cov1=np.cov(male_Train.T)
cov2=np.cov(female_train.T)

TrueResults=0
for i in range(len(male_test)):
    x=male_test.iloc[i]
    x=np.array(x)
    p1=math.exp(-0.5*np.matmul((x-mean1).T,np.matmul(np.linalg.inv(cov1),(x-mean1))))
    p2=math.exp(-0.5*np.matmul((x-mean2).T,np.matmul(np.linalg.inv(cov2),(x-mean2))))
    if(p1>p2):
        TrueResults+=1

for i in range(len(female_test)):
    x=female_test.iloc[i]
    x=np.array(x)
    p1=math.exp(-0.5*np.matmul((x-mean1).T,np.matmul(np.linalg.inv(cov1),(x-mean1))))
    p2=math.exp(-0.5*np.matmul((x-mean2).T,np.matmul(np.linalg.inv(cov2),(x-mean2))))
    if(p2>p1):
        TrueResults+=1

print("The accuracy of the model is:",(TrueResults/10)*100,"%")