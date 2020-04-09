sx, sy = int(input("\nSize of X array: ")), int(input("\nSize of Y array: "))

x, y = list(), list()
print("\nEnter the values of X")
for i in range(sx):
	x.append(int(input(">> ")))
print("\nEnter the values of Y")
for i in range(sy):
	y.append(int(input(">> ")))

import math

count = 0
for i in x:
	for j in y:
		if j*(math.log(i)) > i*(math.log(j)):
			count += 1
print("\nThe no.of pairs = ", count, "\n")