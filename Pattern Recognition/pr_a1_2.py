import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("Iris.csv")
data = data.drop(["Id", "SepalLengthCm", "SepalWidthCm"], axis=1)

flower1 = data.iloc[0]
flower51 = data.iloc[50]
flower101 = data.iloc[100]
data = data.drop([0, 50, 100], axis=0)

plt.scatter(data[data["Species"] == "Iris-setosa"]["PetalLengthCm"],
            data[data["Species"] == "Iris-setosa"]["PetalWidthCm"], color="red")
plt.scatter(data[data["Species"] == "Iris-versicolor"]["PetalLengthCm"],
            data[data["Species"] == "Iris-versicolor"]["PetalWidthCm"], color="blue")
plt.scatter(data[data["Species"] == "Iris-virginica"]["PetalLengthCm"],
            data[data["Species"] == "Iris-virginica"]["PetalWidthCm"], color="green")
plt.legend(["Iris-setosa", "Iris-versicolor", "Iris-virginica"])
plt.xlabel("Petal Length")
plt.ylabel("Petal Width")
plt.title("Distribution of the data")
plt.show()

setosa = data[data["Species"] == "Iris-setosa"]
versicolor = data[data["Species"] == "Iris-versicolor"]
virginica = data[data["Species"] == "Iris-virginica"]

setosa = setosa.drop(["Species"], axis=1)
versicolor = versicolor.drop(["Species"], axis=1)
virginica = virginica.drop(["Species"], axis=1)

flower1_species = flower1["Species"]
flower51_species = flower51["Species"]
flower101_species = flower101["Species"]
flower1 = flower1.drop(["Species"])
flower51 = flower51.drop(["Species"])
flower101 = flower101.drop(["Species"])
print("The species of ")
print("flower 1 is", flower1_species)
print("flower 51 is", flower51_species)
print("flower 101 is", flower101_species)


def mahalanobisDistance(x, mean, cov):
    return np.sqrt(np.dot(np.dot((x-mean).T, np.linalg.inv(cov)), (x-mean)))


print(np.array(flower1[0:]))
print(flower1[0:]-setosa[["PetalLengthCm", "PetalWidthCm"]].mean().values)


flower1_mD = np.array([mahalanobisDistance(np.array(flower1[0:]), setosa[["PetalLengthCm", "PetalWidthCm"]].mean().values, setosa[["PetalLengthCm", "PetalWidthCm"]].cov().values), mahalanobisDistance(flower1[0:], versicolor[[
    "PetalLengthCm", "PetalWidthCm"]].mean().values, versicolor[["PetalLengthCm", "PetalWidthCm"]].cov().values), mahalanobisDistance(flower1[0:], virginica[["PetalLengthCm", "PetalWidthCm"]].mean().values, virginica[["PetalLengthCm", "PetalWidthCm"]].cov().values)])
flower51_mD = np.array([mahalanobisDistance(flower51[0:], setosa[["PetalLengthCm", "PetalWidthCm"]].mean().values, setosa[["PetalLengthCm", "PetalWidthCm"]].cov().values), mahalanobisDistance(flower51[0:], versicolor[[
    "PetalLengthCm", "PetalWidthCm"]].mean().values, versicolor[["PetalLengthCm", "PetalWidthCm"]].cov().values), mahalanobisDistance(flower51[0:], virginica[["PetalLengthCm", "PetalWidthCm"]].mean().values, virginica[["PetalLengthCm", "PetalWidthCm"]].cov().values)])
flower101_mD = np.array([mahalanobisDistance(flower101[0:], setosa[["PetalLengthCm", "PetalWidthCm"]].mean().values, setosa[["PetalLengthCm", "PetalWidthCm"]].cov().values), mahalanobisDistance(flower101[0:], versicolor[[
    "PetalLengthCm", "PetalWidthCm"]].mean().values, versicolor[["PetalLengthCm", "PetalWidthCm"]].cov().values), mahalanobisDistance(flower101[0:], virginica[["PetalLengthCm", "PetalWidthCm"]].mean().values, virginica[["PetalLengthCm", "PetalWidthCm"]].cov().values)])

print("The Mahalanobis Distance between the mean of each class")
print("flower 1 is ", flower1_mD)
print("flower 51 is ", flower51_mD)
print("flower 101 is ", flower101_mD)


flower1_class = np.argmin(flower1_mD)
flower51_class = np.argmin(flower51_mD)
flower101_class = np.argmin(flower101_mD)
print("The class of ")
print("flower 1 is ", flower1_class)
print("flower 51 is ", flower51_class)
print("flower 101 is ", flower101_class)

if flower1_class == 0:
    flower1_class = "Iris-setosa"
elif flower1_class == 1:
    flower1_class = "Iris-versicolor"
else:
    flower1_class = "Iris-virginica"
if flower51_class == 0:
    flower51_class = "Iris-setosa"
elif flower51_class == 1:
    flower51_class = "Iris-versicolor"
else:
    flower51_class = "Iris-virginica"
if flower101_class == 0:
    flower101_class = "Iris-setosa"
elif flower101_class == 1:
    flower101_class = "Iris-versicolor"
else:
    flower101_class = "Iris-virginica"

print("The species of ")
print("flower 1 is", flower1_class)
print("flower 51 is", flower51_class)
print("flower 101 is", flower101_class)

plt.scatter(setosa["PetalLengthCm"], setosa["PetalWidthCm"],
            color="red", label="Iris-setosa")
plt.scatter(versicolor["PetalLengthCm"], versicolor["PetalWidthCm"],
            color="blue", label="Iris-versicolor")
plt.scatter(virginica["PetalLengthCm"], virginica["PetalWidthCm"],
            color="green", label="Iris-virginica")
plt.scatter(flower1["PetalLengthCm"], flower1["PetalWidthCm"],
            color="orange", label="flower 1")
plt.scatter(flower51["PetalLengthCm"],
            flower51["PetalWidthCm"], color="violet", label="flower 51")
plt.scatter(flower101["PetalLengthCm"],
            flower101["PetalWidthCm"], color="pink", label="flower 101")
plt.xlabel("Petal Length")
plt.ylabel("Petal Width")
plt.legend()
plt.show()
