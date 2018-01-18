## SIEVE OF ERATOSTHENES

TIME COMPLEXITY : O( n log (log n) )

```cpp
const int maxn = 1e6 + 5;
int sq = sqrt(maxn);
bool composite[maxn];

void doit() {
	composite[0] = composite[1] = true;
	for(int i = 2; i <= sq; i++) if(!composite[i]) {
		for(int j = 2 * i; j <= maxn; j += i)
			composite[j] = true;
	}
}
```
