n = int(input("\nSize of array: "))

a = []
print("\nEnter the values: ")
for _ in range(n):
	a.append(int(input(">> ")))

r = []
m, b, s = -2147483648, [], -2147483648
for i in range(n):
	if a[i] > s + a[i]:
		b = []
		s = a[i]
		b.append(a[i])
	else:
		s = s + a[i]
		b.append(a[i])
	if s > m:
		m = s
		r = b[0::]

print("\nThe result array is:", r)
print("\nSum is:", m, "\n")