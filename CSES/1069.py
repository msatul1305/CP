def max(a, b):
	if a > b: return a
	return b

def main():
	s = raw_input()
	c, ans = 0, -1
	for i in range(1, len(s)):
		if s[i] == s[i - 1]: c += 1
		else: c = 0
		ans = max(ans, c)
	print ans + 1
main()
