from functions1 import *
import matplotlib.pyplot as plt #thư viện vẽ biểu đồ
dataset = np.loadtxt('Result.txt', delimiter=',')
X = np.copy(dataset)
X[:, 1] = X[:, 0]
X[:, 0] = 1
y = dataset[:, 1]
theta, iter = grad_desc(X, y)

y_pred = pred_value(X, theta)
logistic = logistic_func(X, theta)
print("Correctly predicted labels:", np.sum(y == y_pred))

X0 = X[np.where(y == 0)]
y0 = y[np.where(y == 0)]
X1 = X[np.where(y == 1)]
y1 = y[np.where(y == 1)]
plt.plot(X0, y0, 'ro', markersize = 8)
plt.plot(X1, y1, 'bs', markersize = 8)
plt.axis([-2, 8, -0.5, 1.5])
xx = np.linspace(0, 6, 20)
plt.plot(xx, logistic, '-b')
plt.show()
