# Anuj.K
# CS20B1100

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.naive_bayes import GaussianNB

# Load the iris dataset and extract the Petal Length and Petal Width features
iris = load_iris()
X = iris.data[:, 2:4]
y = iris.target

# Create a Gaussian Naive Bayes classifier and fit the training data
gnb = GaussianNB()
gnb.fit(X[:120], y[:120])

# Compute the accuracy of the classifier on the test data
acc = gnb.score(X[120:], y[120:])
print('Accuracy:', acc)

# Create a meshgrid of points in the feature space
x_min, x_max = X[:, 0].min() - 0.5, X[:, 0].max() + 0.5
y_min, y_max = X[:, 1].min() - 0.5, X[:, 1].max() + 0.5
xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.1),
                     np.arange(y_min, y_max, 0.1))

# Compute the discriminant function for each point in the meshgrid
Z = gnb.predict(np.c_[xx.ravel(), yy.ravel()])

# Reshape the predicted class labels to the meshgrid shape
Z = Z.reshape(xx.shape)

# Plot the decision boundary and the data points
plt.contourf(xx, yy, Z, alpha=0.4)
plt.scatter(X[:, 0], X[:, 1], c=y, alpha=0.8)
plt.xlabel('Petal Length')
plt.ylabel('Petal Width')
plt.title('Decision Boundary for Iris Dataset')
plt.show()
