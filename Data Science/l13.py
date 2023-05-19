import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import MinMaxScaler


class KNN():
	'''
 	Overall inference:

		When the data is not normalized we are getting low accuracy but it is increasing with K at the beginning. But when the data is normalized using min mac scalar, model got the ability to classify metals with more accuracy but K = 3 has the highest accuracy and it is decreased for K = 5.

		The level of effect of feature scaling is very high, i.e. normalization. Features with values varying in the larger range will play bigger role in decision making algorithm. So normalizing that data facilitates all features on a certain scale which allow model to perform better.

	'''

	def __init__(self):
		self.data = pd.read_csv("SteelPlateFaults-2class.csv")

	def classify_without_normalization(self, feature_list):
		print("\n---------------WITHOUT NORMALIZATION----------------\n")
		features = self.data[feature_list].to_numpy()
		labels = self.data["Class"].to_numpy()
		features_train, features_test, labels_train, labels_test = train_test_split(
			features, labels, test_size=0.3, random_state=42, shuffle=True)
		print("\n---------------K = 1----------------\n")
		clf_1 = KNeighborsClassifier(n_neighbors=1, weights="distance")
		clf_1.fit(features_train, labels_train)
		labels_pred_1 = clf_1.predict(features_test)
		print("Confusion Matrix: ")
		print(confusion_matrix(labels_test, labels_pred_1))
		accuracy_1 = accuracy_score(labels_test, labels_pred_1)
		print(f'Accuracy Score: {accuracy_1}')
		print("\n---------------K = 3----------------\n")
		clf_3 = KNeighborsClassifier(n_neighbors=3, weights="distance")
		clf_3.fit(features_train, labels_train)
		labels_pred_3 = clf_3.predict(features_test)
		print("Confusion Matrix: ")
		print(confusion_matrix(labels_test, labels_pred_3))
		accuracy_3 = accuracy_score(labels_test, labels_pred_3)
		print(f'Accuracy Score: {accuracy_3}')
		print("\n---------------K = 5----------------\n")
		clf_5 = KNeighborsClassifier(n_neighbors=5, weights="distance")
		clf_5.fit(features_train, labels_train)
		labels_pred_5 = clf_5.predict(features_test)
		print("Confusion Matrix: ")
		print(confusion_matrix(labels_test, labels_pred_5))
		accuracy_5 = accuracy_score(labels_test, labels_pred_5)
		print(f'Accuracy Score: {accuracy_5}')
		acc = [0, accuracy_1, 0, accuracy_3, 0, accuracy_5]
		print("\n-------------------------------------\n")
		print(
			f"\nAccuracy is highest for : K = {acc.index(max(acc))} and its Accuracy = {max(acc)}\n")
		print("\n-------------------------------------\n")

	def classify_with_normalization(self, feature_list):
		print("\n---------------WITH NORMALIZATION----------------\n")
		features = self.data[feature_list].to_numpy()
		scalar = MinMaxScaler()
		normalized_features = scalar.fit_transform(features)
		labels = self.data["Class"].to_numpy()
		features_train, features_test, labels_train, labels_test = train_test_split(
			normalized_features, labels, test_size=0.3, random_state=42, shuffle=True)
		print("\n---------------K = 1----------------\n")
		clf_1 = KNeighborsClassifier(n_neighbors=1, weights="distance")
		clf_1.fit(features_train, labels_train)
		labels_pred_1 = clf_1.predict(features_test)
		print("Confusion Matrix: ")
		print(confusion_matrix(labels_test, labels_pred_1))
		accuracy_1 = accuracy_score(labels_test, labels_pred_1)
		print(f'Accuracy Score: {accuracy_1}')
		print("\n---------------K = 3----------------\n")
		clf_3 = KNeighborsClassifier(n_neighbors=3, weights="distance")
		clf_3.fit(features_train, labels_train)
		labels_pred_3 = clf_3.predict(features_test)
		print("Confusion Matrix: ")
		print(confusion_matrix(labels_test, labels_pred_3))
		accuracy_3 = accuracy_score(labels_test, labels_pred_3)
		print(f'Accuracy Score: {accuracy_3}')
		print("\n---------------K = 5----------------\n")
		clf_5 = KNeighborsClassifier(n_neighbors=5, weights="distance")
		clf_5.fit(features_train, labels_train)
		labels_pred_5 = clf_5.predict(features_test)
		print("Confusion Matrix: ")
		print(confusion_matrix(labels_test, labels_pred_5))
		accuracy_5 = accuracy_score(labels_test, labels_pred_5)
		print(f'Accuracy Score: {accuracy_5}')
		acc = [0, accuracy_1, 0, accuracy_3, 0, accuracy_5]
		print("\n-------------------------------------\n")
		print(
			f"\nAccuracy is highest for : K = {acc.index(max(acc))} and its Accuracy = {max(acc)}\n")
		print("\n-------------------------------------\n")


if __name__ == "__main__":
	choice = 1
	clf = KNN()
	features_list = [col for col in clf.data.columns if col != "Class"]
	while(choice != 4):
		print("\n1. KNN without normalization.")
		print("2. KNN with normalization")
		print("3. Overall inference")
		print("4. Exit")
		choice = int(input("Enter your choice: "))
		if(choice == 1):
			clf.classify_without_normalization(features_list)
		elif(choice == 2):
			clf.classify_with_normalization(features_list)
		elif(choice == 3):
			print(clf.__doc__)
		elif(choice == 4):
			print("Program is exited.\n")
			exit(0)
		else:
			print("Please enter a valid choice.\n")
