from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score
from sklearn import model_selection
from sklearn import tree
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

def importdata():

	dataset = pd.read_csv('titanic.csv')
	print(dataset)
	dataset.drop('cabin', inplace=True, axis=1)
	dataset.drop('body', inplace=True, axis=1)
	dataset.drop('boat', inplace=True, axis=1)
	dataset.drop('home.dest', inplace=True, axis=1)
	dataset = pd.DataFrame(dataset).dropna()
	
	return dataset

def splitdataset(dataset):

	Y = dataset.iloc[:,1:2]
	X = dataset.copy()
	X.drop('survived', inplace=True, axis=1)
	X = pd.DataFrame(X).apply(LabelEncoder().fit_transform)
	X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.25, random_state=10)
	
	return X, Y, X_train, X_test, y_train, y_test

def train_using_gini(X_train, y_train):

	clf_gini = DecisionTreeClassifier(criterion = "gini",
            random_state = 100,max_depth=10, min_samples_leaf=5)
	clf_gini.fit(X_train, y_train)

	return clf_gini

def Randomforest(X_train, y_train):

	forest = RandomForestClassifier()
	forest.fit(X_train, y_train.values.ravel())

	return forest


def prediction(X_test, clf_object):

	y_pred = clf_object.predict(X_test)
	print("Predicted values:")
	print(y_pred)

	return y_pred

def cal_accuracy(y_test, y_pred):
      
	print("Confusion Matrix: ",
	confusion_matrix(y_test, y_pred))
      
	print ("Accuracy : ",
	accuracy_score(y_test,y_pred)*100)
      
def plot(clf_object):

	fig = plt.figure(figsize=(15,10))
	_ = tree.plot_tree(clf_object,  
					class_names='survived',
					filled=True)

data = importdata()
X, Y, X_train, X_test, y_train, y_test = splitdataset(data)
clf_gini = train_using_gini(X_train, y_train)


print("Results Using Gini Index:")
y_pred_gini  = prediction(X_test, clf_gini)
cal_accuracy(y_test, y_pred_gini)


forest = Randomforest(X_train, y_train)
y_pred_forest = prediction(X_test, forest)
print("Results Using Random Forest:")
cal_accuracy(y_test, y_pred_forest)





