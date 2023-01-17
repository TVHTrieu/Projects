import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import pandas as pd
from functions import *
from functions1 import *
dataset = pd.read_csv('dataset1.csv')
y = dataset.iloc[:, -1].values
raw = dataset.iloc[:, :].values
X1 = np.ones([np.size(raw, 0), np.size(raw, 1) + 1])
X1[:, 1:] = raw[:, :]
[X1 , mu, s] = Normalize(X1)
theta = np.zeros(np.size(X1, 1))
Theta, iter = grad_desc(X1, y)
print(len(y));
print("Estimated regression coefficients:", Theta)
print("No. of iterations:", iter)
y_pred = pred_values(X1, Theta)
print("Correctly predicted labels:", np.sum(y_pred == y))
print(y)


'''
np.random.shuffle(raw)
X = np.ones([np.size(raw, 0), np.size(raw, 1) + 1])
X[:, 1:] = raw[:, :]
[X, mu, s] = Normalize(X[:, :-1])
print(X)
'''
'''
y = dataset.iloc[:, -1].values
Theta, iter = grad_desc(X, y)
print("Estimated regression coefficients:", Theta)
print("No. of iterations:", iter)
'''

x_0 = X1[np.where(y == 0.0)]
x_1 = X1[np.where(y == 1.0)]
plt.scatter([x_0[:, 1]], [x_0[:, 2]], c='b', label='y = 0')
plt.scatter([x_1[:, 1]], [x_1[:, 2]], c='r', label='y = 1')
x1 = np.arange(-2.5, 2, 0.1)
x2 = -(Theta[0] + Theta[1] * x1) / Theta[2]
plt.plot(x1, x2, c='k', label='reg line')

plt.xlabel('x1')
plt.ylabel('x2')
plt.legend()
plt.show()
