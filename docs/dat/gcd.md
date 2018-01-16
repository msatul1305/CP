## GCD & LCM

```cpp
#include <cstdio>

//O-> log(a*b)
int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

//O-> log(a*b)
int __lcm(int a, int b) {
	return (a / gcd(a * b) * b);
}
```

#### Reduce a fraction
```
		scanf("%d %d", &numerator, &denominator);
		int lcm = __lcm(numerator, denominator);
		printf("%d/%d\n", lcm/denominator, lcm/numberator);
```
