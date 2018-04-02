def main():
	n = int(raw_input())
	if n == 1: print 1
	elif n < 4: print "NO SOLUTION"
	elif n == 4:
		print "3 1 4 2"
	else:
		for i in range (1, n + 1):
			if(i&1): print i,
		for i in range (1, n + 1):
			if(i&1 == 0): print i,

main()
