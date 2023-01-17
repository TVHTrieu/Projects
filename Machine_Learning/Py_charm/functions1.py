import math

import numpy as np


def logistic_func(X, Theta):
    return 1.0 / (1 + np.exp(-(X @ Theta)))


def log_gradient(X, y, Theta):
    first_calc = logistic_func(X, Theta) - y
    final_calc = X.T @ first_calc
    return final_calc


def cost_func(X, y, Theta):
    log_func_v = logistic_func(X, Theta)
    step1 = y * np.log(log_func_v)
    step2 = (1 - y) * np.log(1 - log_func_v)
    m = np.size(y)
    final = -step1 - step2
    sum_final = np.sum(final)
    J = 1 / m * sum_final
    return J


def normalize(X):
    '''
    function to normalize feature matrix, X
    '''
    mins = np.min(X, axis=0)
    maxs = np.max(X, axis=0)
    rng = maxs - mins
    norm_X = 1 - ((maxs - X) / rng)
    return norm_X


def grad_desc(X, y, alpha=0.01, coverage_change=0.1):
    theta = np.zeros(np.size(X, 1))
    cost = cost_func(X, y, theta)
    change_cost = 1
    iter = 1
    while change_cost > coverage_change:
        old_cost = cost
        theta = theta - (alpha * log_gradient(X, y, theta))
        cost = cost_func(X, y, theta)
        change_cost = old_cost - cost
        iter += 1
    return theta, iter


def pred_values(X, Theta):
    pred_prob = logistic_func(X, Theta)
    pred_value = np.where(pred_prob >= 0.5, 1, 0)
    return pred_value
