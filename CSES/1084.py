def main():
	n, m, k = map(int, raw_input().strip().split())
	app = [int(i) for i in raw_input().strip().split()]
	sz = [int(i) for i in raw_input().strip().split()]
	sz.sort()
	app.sort()
	a, b, ans = 0, 0, 0
	while a < n and b < m:
		if sz[b] <= app[a] + k and sz[b] >= app[a] - k:
			a, b, ans = a + 1, b + 1, ans + 1
		elif sz[b] > app[a] + k:
			a += 1
		elif sz[b] < app[a] - k:
			b += 1
	print ans

main()
