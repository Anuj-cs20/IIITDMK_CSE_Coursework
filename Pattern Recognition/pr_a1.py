import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

H1 = np.array([0.24, 0.2, 0.16, 0.12, 0.08, 0.04, 0.12, 0.04])
H2 = np.array([0.22, 0.23, 0.16, 0.13, 0.11, 0.08, 0.05, 0.02])

plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.bar(np.arange(8), H1)
plt.title("Histogram H1")
plt.subplot(1, 2, 2)
plt.bar(np.arange(8), H2)
plt.title("Histogram H2")
plt.show()


def KLDistance(H1, H2):
    return np.sum(H1*np.log(H1/H2))


def bhattacharyyaDistance(H1, H2):
    return -np.log(np.sum(np.sqrt(H1*H2)))


print("KL distance between H1 and H2 is", KLDistance(H1, H2))
print("Bhattacharyya distance between H1 and H2 is",
      bhattacharyyaDistance(H1, H2))


def QFDistance(hq_htT, A):
    return np.sqrt(np.dot(np.dot(hq_htT, A), hq_htT.T))


hq_htT = np.array([0.5, 0.5, -0.5, -0.25, -0.25])

A = np.array([[1, 0.135, 0.195, 0.137, 0.157], [0.135, 1, 0.2, 0.309, 0.143], [
             0.195, 0.2, 1, 0.157, 0.122], [0.137, 0.309, 0.157, 1, 0.195], [0.157, 0.143, 0.122, 0.195, 1]])


print("The quadratic form distance is", QFDistance(hq_htT, A))

doc1 = "MATLAB is a program for solving engineering and mathematical problems. The basic MATLAB objects are vectors and matrices, so you must be familiar with these before making extensive use of this program."
doc2 = "MATLAB works with essentially one kind of object, a rectangular numerical matrix. Here is some basic information on using MATLAB matrix commands"


def cosineDistance(doc1, doc2):

    d1 = doc1.lower()
    d2 = doc2.lower()

    punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
    for x in d1:
        if x in punctuations:
            d1 = d1.replace(x, "")
    for x in d2:
        if x in punctuations:
            d2 = d2.replace(x, "")

    d1 = d1.split()
    d2 = d2.split()

    unique = list(set(d1+d2))

    v1 = np.zeros(len(unique))
    v2 = np.zeros(len(unique))

    for i in range(len(unique)):
        v1[i] = d1.count(unique[i])
        v2[i] = d2.count(unique[i])
    # cosine distance
    return 1-np.dot(v1, v2)/(np.linalg.norm(v1)*np.linalg.norm(v2))


print("The cosine distance between the two documents is",
      cosineDistance(doc1, doc2))
