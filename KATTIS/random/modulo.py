def main():
    s = set()
    for i in range(10):
        z = int(input())
        s.add(z % 42)
    print len(s)
        
main()
