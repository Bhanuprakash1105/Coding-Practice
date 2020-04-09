def sortThis(v):
	v.sort()
	return v

def anagrams(a):
	a = [sortThis(list(x)) for x in a]
	check = [False]*len(a)	
	b = list()
	for i in range(0, len(a)):
		if not check[i]:
			temp = list()
			for j in range(i, len(a)):
				if a[i] == a[j]:
					temp.append(j)
					check[j] = True
			b.append(temp)
	return b

n = int(input("\nSize of array: "))
a = list()
print("\nEnter the {0} strings\n".format(n))
for i in range(n):
	a.append(input("{0} >> ".format(i+1)))

r = anagrams(a)

print("\nThe anagrams list is:", r, "\n")