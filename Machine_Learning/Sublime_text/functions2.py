import numpy as np 
import sys
import math
from matplotlib import pyplot

def ReadData(fileName): 
  
    # Read the file, splitting by lines 
	f = open(fileName, 'r') 
	lines = f.read().splitlines()
	f.close() 
  
	items = [] 
  
	for i in range(0, len(lines)): 
		line = lines[i].split(',') 
		itemFeatures = [] 
  
		for j in range(len(line)-1): 
              
            # Convert feature value to float
			v = float(line[j]) 
              
            # Add feature value to dict 
			itemFeatures.append(v) 
  
		items.append(itemFeatures) 


  
	return items 

def MaxMin(items):
	n = len(items[0])
	minima = [sys.maxsize for i in range(n)]
	maxima = [-sys.maxsize - 1 for i in range(n)]

	for item in items:
		for j in range(len(item)):
			if item[j] < minima[j]:
				minima[j] = item[j]

			if item[j] > maxima[j]:
				maxima[j] = item[j]
	return minima, maxima

def InitializeMeans(Cmin, Cmax, items, k):
	f = len(items[0])
	means = [[0 for i in range(f)] for j in range(k)]

	for mean in means:
		for j in range(len(mean)):
			mean[j] = np.random.uniform(Cmin[j] + 1, Cmax[j] - 1)

	return means 

def EuclideanDistance(x, y):
	S = 0
	for i in range(len(x)):
		S += math.pow(x[i]-y[i], 2)

	return math.sqrt(S)

def UpdateMeans(mean, item, n):
	for i in range(len(mean)):
		m = mean[i]
		m = (m*(n-1)+item[i])/float(n)
		mean[i] = round(m, 3)
      

	return mean

def Classify(means,item):  
	minimum = sys.maxsize
	index = -1
  
	for i in range(len(means)):

		dis = EuclideanDistance(item, means[i])

		if (dis < minimum):
			minimum = dis
			index = i
      
	return index

def CalculateMeans(k, items, maxIterations=100000):
	Cmin, Cmax = MaxMin(items)

	means = InitializeMeans(Cmin, Cmax, items, k)

	#Số điểm dữ liệu của mỗi cụm
	clusterSize = [0 for i in range(len(means))]

	#Dùng để lưu kết quả sau mỗi vòng lặp nếu vị trí của 
	#những phần tử ở mỗi cụm giống với vòng lặp trước thì dừng
	belongsTo = [0 for i in range(len(items))]

	for i in range(maxIterations):
		noChange = True
		for j in range(len(items)):

			item = items[j]

			index = Classify(means, item)


			clusterSize[index] += 1
			cSize = clusterSize[index]

			means[index] = UpdateMeans(means[index], item, cSize)

			if(index != belongsTo[j]):
				noChange = False

			belongsTo[j] = index

		if (noChange):
			break
			

	return means
	
def FindClusters(means,items):
	clusters = [[] for i in range(len(means))] # Init clusters
      
	for item in items:
  
        # Classify item into a cluster
		index = Classify(means,item)
  
        # Add item to cluster
		clusters[index].append(item)
  
	return clusters

def CutToTwoFeatures(items,indexA,indexB):
	n = len(items);
	X = [];
	for i in range(n):
		item = items[i];
		newItem = [item[indexA],item[indexB]];
		X.append(newItem);

	return X;
        

def PlotClusters(clusters):
	n = len(clusters);
    #Cut down the items to two dimension and store to X
	X = [[] for i in range(n)];

	for i in range(n):
		cluster = clusters[i];
		for item in cluster:
			X[i].append(item);


	colors = ['r','b','g','c','m','y'];

	pyplot.figure(1)
	for x in X:
        #Choose color randomly from list, then remove it
        #(to avoid duplicates)
		c = np.random.choice(colors);
		colors.remove(c);

		Xa = [];
		Xb = [];

		for item in x:
			Xa.append(item[0]);
			Xb.append(item[1]);

		pyplot.plot(Xa,Xb,'x',color=c);

	#pyplot.show()