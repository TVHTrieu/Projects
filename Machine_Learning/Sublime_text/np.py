import numpy as np

#_A = [[1,2,3],[4,5,6]]
#A = np.array(_A)
#print(A)
#print('a[0,1]:', A[0,1])
#print('a[:,1]:', A[:,1])
#print('a[1,:]:', A[1,:])
#_B = [[2,3,5],[7,9,21]]
#B = np.array(_B)
#print('A + B: \n', A + B)
#print('A - B: \n', A - B)
#print('A * 2: \n', A * 2)
#print('A / 2: \n', A / 2)

#Nhân ma trận với vector
_a = [ [ 1, 2 ], [ 3, 4 ], [ 5, 6 ] ]
a = np.array(_a) #Create a 3 * 2 matrix
_b = [ 1, 2 ]
b = np.array(_b) #Create a 2-dimension vector
print(a)
print(b)
print('a * b:', a.dot(b)) #print out a * b using narray.dot()
print('a * b:', a @ b) #print out a * b using @ operation
print('\n')

#Nhân ma trận với ma trận
_a = [ [ 1, 2 ], [ 3, 4 ], [ 5, 6 ] ]
a = np.array(_a) #Create a 3 * 2 matrix
_b = [ [1, 3], [2, 1] ]
b = np.array(_b) #Create a 2 * 2 matrix
print(a)
print(b)
print('a * b:', a.dot(b)) #print out a * b using narray.dot()
print('a * b:', a @ b) #print out a * b using @ operation
print('\n')

#Ma trận đơn vị
a = np.eye(5)
print(a)
print('\n')

#element-wise
_a = [ [ 1, 2, 3 ], [ 4, 5, 6 ] ]
_b = [ [ 2, 3, 5], [7, 9, 21] ]
a = np.array(_a) #create 2 * 3 matrix: a
b = np.array(_b) #create 2 * 3 matrix: b
print('a .* b:', a * b) #print out a .* b

#Toán tử logic với ma trận: Kết quả trả ra sẽ được ghi vào một ma trận với kích thước tương đương.
a = np.eye(5)
print(a == 1)
print('\n')

#Ma trận nghịch đảo
a = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]
a = np.array(_a)
a_i = np.linalg.pinv(a) #Create inverse of a
print(a_i)
print(a @ a_i)
print('\n')

#Ma trận chuyển vị
_a = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]
a = np.array(_a)
a_t = np.transpose(a) #Create transpose of a
print(a)
print(a_t)
print('\n')

#Hàm size với ma trận
_a = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]
a = np.array(_a)
print(np.size(a))
print(np.size(a, 1))
print('\n')

#Hàm sum và max/min với ma trận
_a = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]
a = np.array(_a)
print(np.sum(a, 0))
print(np.max(a))
print(np.min(a, 1))