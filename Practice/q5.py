n = int(input("\nEnter the size: "));

a = set()
print("\nEnter the values: ")
for x in range(n):
	a.add(int(input(">> ")))

a = list(a)

print("\nSet = ",a)
n = len(a)

d, count, x = dict(), 1, 0
for i in range(0, n-1, 1):
	if a[i]+1 == a[i+1]:
		count += 1
	else:
		d[x] = count
		count = 1
		i += 1
		x = i
d[x] = count

print("\nDict = ",d)

m, index = 0, 0
for key, value in d.items():
	if value > m:
		m = value
		index = key

print("\nThe result is: ",a[index:index+m:1],"\n")

