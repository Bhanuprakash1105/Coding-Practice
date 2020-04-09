def total_inc_dec(x):
	d = {0:1, 1:10, 2:100, 3:475, 4:1675, 5:4954, 6:12953, 7:38817}
	if x >= 0 and x <= 7:
		return d[x]
	x = 10**x
	count = 1
	n = 10**7
	while n < x:
		flag = ""
		m, countFlag = -1, True
		s = str(n)
		q, i = n, 0
		while i < len(s):
			curr = int(s[i])
			if m == -1:
				m = curr
				i += 1
				continue
			if i == 1 or flag == "equal":
				if curr > m:
					flag = "increasing"
				elif curr < m:
					flag = "decreasing"
				else:
					flag = "equal"
					i += 1
					continue
			if (curr > m and flag == "decreasing") or (curr < m and flag == "increasing"):
				countFlag = False
				break
			else:
				m = curr
			i += 1
		if countFlag:
			count += 1
		n += 1
	return count + d[7]

i = int(input("\nEnter the x where x -> 10^x for increase/decrease number count: "))

print("\nThe result is:", total_inc_dec(i),"\n")
