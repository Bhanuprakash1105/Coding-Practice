s = input("\nEnter the string: ")
a = [int(x) for x in s]
count = 0
for i in range(0, len(a), 1):
	if a[i] == 0:
		m = True
	else:
		m = False
	if i-1 >= 0:
		if a[i-1] == 0:
			left = True
		else:
			left = False
	else:
		left = True
	if i+1 < len(a):
		if a[i+1] == 0:
			right = True
		else:
			right = False
	else:
		right = True
	if left and m and right:
		count += 1		
print("\nThe no.of buildings that will not be destroyed =", count, "\n")