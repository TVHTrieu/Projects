import numpy as np 
def logistic_func(X, Theta):
	return 1/(1 + np.exp(-X@Theta))

def log_gradient(X, y, Theta):
	first_calc = logistic_func(X, Theta) - y
	final_calc = X.T @ first_calc
	return final_calc

def cost_func(X, y, Theta):
	log_func_v = logistic_func(X, Theta)
	step1 = y * np.log(log_func_v)
	step2 = (1 - y) * np.log(1 - log_func_v)
	final = -step1 - step2
	sum = np.sum(final)
	m = np.size(y)
	J = (1/m)*sum
	return J

def grad_desc(X, y, lr=.01, converge_change=.00001):
	theta = np.zeros(np.size(X, 1))
	cost = cost_func(X, y, theta)
	change_cost = 1
	iter = 0

	while change_cost > converge_change:
		old_cost = cost
		theta = theta - (lr*log_gradient(X, y, theta))
		cost = cost_func(X, y, theta)
		change_cost = old_cost - cost
		iter += 1

	return theta, iter

def pred_value(X, Theta):
	pred_prob = logistic_func(X, Theta)
	pred_value = np.where(pred_prob >= 0.5, 1, 0)
	return pred_value

