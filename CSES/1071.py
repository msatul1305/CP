def max(a, b):
	if a > b: return a
	return b

def main():
	t = int(raw_input())
	while t != 0:
		a = [int(i) for i in raw_input().strip().split()]
		n = max(a[0], a[1])
		if n&1:
			print (n*n - (n-1) + a[1] - a[0])
		else:
			print (n*n - (n-1) + a[0] - a[1])
		t = t-1
main()
