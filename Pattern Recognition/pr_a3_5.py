import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score

faceData = pd.read_csv('face.csv')
faceData['target'].unique()

test_data = faceData.groupby('target').apply(
    lambda x: x.head(2)).reset_index(drop=True)
train_data = faceData.groupby('target').apply(
    lambda x: x.tail(8)).reset_index(drop=True)

X_train, y_train = train_data.iloc[:, :-1], train_data.iloc[:, -1]
X_test, y_test = test_data.iloc[:, :-1], test_data.iloc[:, -1]


class LDA:
    def __init__(self, n_components):
        self.n_components = n_components
        self.components = None
        self.mean = None

    def fit(self, X, y):
        n_features = X.shape[1]
        class_labels = np.unique(y)

        self.mean = np.mean(X, axis=0)

        SW = np.zeros((n_features, n_features))
        SB = np.zeros((n_features, n_features))

        for c in class_labels:
            X_c = X[y == c]
            mean_c = np.mean(X_c, axis=0)
            SW += (X_c - mean_c).T.dot((X_c - mean_c))

            n_c = X_c.shape[0]
            mean_diff = (mean_c - self.mean).reshape(n_features, 1)
            SB += n_c * (mean_diff).dot(mean_diff.T)

        A = np.linalg.inv(SW).dot(SB)

        self.eigenvalues, self.eigenvectors = np.linalg.eigh(A)

        self.eigenvectors = self.eigenvectors.T
        idxs = np.argsort(abs(self.eigenvalues))[::-1]
        self.eigenvalues = self.eigenvalues[idxs]
        self.eigenvectors = self.eigenvectors[idxs]

        if self.n_components > 0:
            self.components = self.eigenvectors[:self.n_components]
        else:
            raise Exception("Minimum dimension should be more than 0")

    def transform(self, X):
        return np.dot(X, self.components.T)

    def plot(self):
        plt.figure(figsize=(32, 18))
        plt.xlabel('Dimensions')
        plt.ylabel('Eigen Values')
        sns.barplot(x=[i for i in range(len(self.eigenvalues))],
                    y=self.eigenvalues)


lda = LDA(39)
lda.fit(X_train.to_numpy(), y_train.to_numpy())
lda.plot()

X_test_transformed = lda.transform(X_test)
X_train_transformed = lda.transform(X_train)

print("d' =", X_train_transformed.shape[1])

X_train_graph = pd.DataFrame(X_train_transformed, columns=[
                             f'PC{i}' for i in range(X_train_transformed.shape[1])])

X_train_graph = pd.concat(
    [X_train_graph, pd.DataFrame(y_train, columns=['target'])], axis=1)

plt.figure(figsize=(32, 18))
sns.scatterplot(data=X_train_graph, x='PC0', y='PC1', hue='target')

model = GaussianNB()
model.fit(X_train_transformed, y_train)
y_pred = model.predict(X_test_transformed)

print("Accuracy =", accuracy_score(y_pred, y_test))
plt.show()