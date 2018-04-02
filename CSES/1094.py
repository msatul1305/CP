def main():
	n = int(raw_input())
	ans = 0
	a = [int(i) for i in raw_input().strip().split()]
	for i in range(0, n - 1):
		if a[i] - a[i + 1] > 0:
			ans = ans + a[i] - a[i + 1]
			a[i + 1] += a[i] - a[i + 1]
	print ans
main()
