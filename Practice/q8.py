from itertools import permutations

a = [int(x) for x in input("\nEnter the values of array: ").split(" ")]

print("\nThe given array is: ",a)

p = permutations(a)

print("\nThe permutations are: ")
for i in list(p):
	print(">> ",i)