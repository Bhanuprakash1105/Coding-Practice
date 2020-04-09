def minor(m, r, c):
	
	if len(m) == 1:
		return m
	
	mt = []
	for i in range(len(m)):
		mst = []
		for j in range(len(m[i])):
			if i != r and j != c:
				mst.append(m[i][j])
		if len(mst) != 0:
			mt.append(mst)
	
	return mt

def determinant(matrix):
	
	if len(matrix[0]) == 1:
		s = matrix[0][0]
		return matrix[0][0]
	
	mp = matrix[0]
	b = []
	for i in range(len(mp)):
		b.append(determinant(minor(matrix, 0, i)))
	
	flag = -1
	s = 0
	for x, y in zip(mp, b):
			flag *= -1
			s = s + flag*x*y
	
	return s

def main():
	n = int(input("\nEnter the size of the matrix: "))

	m = []
	for i in range(n):
		m.append([])
		for j in range(n):
			m[i].append(int(input(">> a[{0}][{1}] = ".format(i+1, j+1))))

	print("\nThe matrix is:", m,"\n")

	print("\nThe determinant is:", determinant(m),"\n")

if __name__ == '__main__':
	main()