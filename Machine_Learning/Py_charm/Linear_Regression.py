from functions import *
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

raw = np.loadtxt('data1.txt', delimiter=',')
X = np.copy(raw)
X[:, 1] = X[:, 0]
X[:, 0] = 1
y = raw[:, 1]
[Theta, costs, iter] = GradientDescent(X, y)
predict = predict(X, Theta)
print(predict)
print('\n')
plt.figure("The best final fit line")
plt.scatter(X[:, 1], y, color='b')
plt.plot(X[:, 1], predict, color='r')
plt.figure("Verification")
plt.plot(range(iter), costs, color='r')
plt.show()
'''
[X, y] = Load('data2.txt')
[X, mu, s] = Normalize(X)
#print(X)
[Theta, costs, iter] = GradientDescent(X, y)
predict = predict(X, Theta)
print(predict)
'''
'''
raw = np.loadtxt('data3.txt',delimiter=',')
np.random.shuffle(raw)
data = np.ones([np.size(raw, 0), np.size(raw, 1) + 1])
data[:, 1:] = raw[:, :]

[data, mu, s] = Normalize(data)

X_cv = data[0:int(np.size(data, 0)*20/100), 0:-1]
y_cv = data[0:int(np.size(data, 0)*20/100), -1]

X_test = data[int(np.size(data, 0)*20/100):int(np.size(data, 0)*40/100), 0: -1]
Y_test = data[int(np.size(data, 0)*20/100):int(np.size(data, 0)*40/100), -1]

X_train = data[int(np.size(data, 0)*40/100):, 0:-1]
y_train = data[int(np.size(data, 0)*40/100):, -1]

alpha = [0.001, 0.003, 0.01, 0.03, 0.1, 0.3, 1]
costs = np.zeros(len(alpha))
for i in range(len(alpha)):
    [Theta, cost, iter] = GradientDescent(X_train, y_train, alpha[i])
    cost[i] = computeCost(X_cv, y_cv, Theta)
'''
'''
[X, y] = Load('data4.txt')
for i in range(2,9):
    X = np.c_[X, X[:, 1]**i]
'''


