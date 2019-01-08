import math
n, k = map(int, input().strip().split())
if math.log2(n) <= k:
    print ("Your wish is granted!")
else:
    print ("You will become a flying monkey!")
