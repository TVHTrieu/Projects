

from functions2 import *
import numpy as np
data = ReadData('data5.txt')
print(data)
data = np.array(data)
print(data)
tb = np.mean(data[:, 0])
print(tb)
min, max = FindColMinMax(data)
means = [[0 for i in range(4)] for j in range(3)]
print(means)
for mean in means:
    for i in range(len(mean)):
        # Set value to a random float
        # (adding +-1 to avoid a wide placement of a mean)
        mean[i] = np.random.uniform(min[i] + 1, max[i] - 1)

print(means)

#print(minima)
#print(maxima)
