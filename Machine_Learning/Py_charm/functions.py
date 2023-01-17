import numpy as np

def predict(X,Theta):
	return X @ Theta

def computeCost(X, y, Theta):
    predicted = predict(X, Theta)
    sqr_error = (predicted - y) ** 2
    sum_error = np.sum(sqr_error)
    m = np.size(y)
    J = (1 / (2 * m)) * sum_error
    return J

def GradientDescent(X,y,alpha=0.02,iter=0,steps=500):
    theta = np.zeros(np.size(X, 1))
    m = np.size(y)
    costs = []
    while 1:
        error = predict(X, theta) - y
        costs.append(computeCost(X, y, theta))
        theta = theta - (alpha * ((1 / m) * (X.T @ error)))
        print(computeCost(X, y, theta))

        iter += 1
        if iter % steps == 0:
            print(iter, "epochs elapsed")
            stop = input("Do you want to stop (y/*??")
            if stop == "y":
                break
    yield theta
    yield costs
    yield iter

def Normalize(X):
    n = np.copy(X)
    n[0, 0] = 100
    s = np.std(n, 0, dtype=np.float32)
    mu = np.mean(n, 0)
    n = (n-mu)/s
    n[:, 0] = 1
    yield n
    yield mu
    yield s

def Load(path):
    try:
        raw = np.loadtxt(path, delimiter=',')
        X = np.copy(raw)
        X[:, 1:] = X[:, :-1]
        X[:, 0] = 1
        y = raw[:, -1]
        yield X
        yield y
    except:
        return 0



