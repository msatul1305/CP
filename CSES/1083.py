def main():
	n = raw_input()
	a = [int(i) for i in raw_input().strip().split()]
	a.sort()
	chk = int(1)
	for i in a:
		if i != chk:
			print chk
			break
		chk = chk + 1
main()
