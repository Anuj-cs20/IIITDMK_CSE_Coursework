import numpy as np
import pandas as pd
from collections import Counter
import matplotlib.pyplot as plt

df1 = pd.read_csv("diabetes1.csv")    # reading csv file in df

df = df1.drop(columns=['Outcome'])

# print(df[0])

for l in df.columns:
    print("\n", l, " : \n")
    print("mean of ", l, " : ", np.mean(df[l]))
    l_array = np.array(df[l])
    l_array = np.sort(l_array)
    print("median of ", l, " : ", np.median(l_array))
    print("mode of ", l, " : ", Counter(l_array).most_common(1)[0][0])
    print("minimum of ", l, " : ", l_array[0])
    print("maximum of ", l, " : ", l_array[len(l_array)-1])
    print("standarad deviation of ", l, " : ",
          np.std(l_array, dtype=np.float64))

print("\n\n")


for val in ['Age', 'BMI']:
    print("\n")
    for l in df.columns:
        print("correlation of ", val, " with ", l, " : ",
              df['Age'].corr(df[l]))


# plotting scatter

for val in ['Age', 'BMI']:
    for l in df.columns:
        plt.xlabel(val)
        plt.ylabel(l)
        plt.scatter(df[val], df[l])
        plt.show()


h = df.hist(column=["Pregnancies", "SkinThickness"])
plt.show()

g_outcome = df1.groupby(["Outcome"])

for val, group in g_outcome:
    print(val)
    plt.hist(group["Pregnancies"])
    plt.show()


df.plot.box()
plt.show()