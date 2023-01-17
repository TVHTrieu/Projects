from functions2 import *
items = ReadData('Flower.txt')
minima, maxima = MaxMin(items)
print(minima, maxima)
'''
items = CutToTwoFeatures(items, 2, 3)
Xa = []
Xb = []

for item in items:
	Xa.append(item[0])
	Xb.append(item[1])
pyplot.figure(2)
pyplot.plot(Xa,Xb,'x',color='y')
'''

k = 3
means= CalculateMeans(k, items)
print(means)
cluster = FindClusters(means, items)
print(np.array(cluster))

'''
PlotClusters(cluster)
pyplot.show()
'''