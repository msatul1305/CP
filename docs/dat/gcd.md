## GCD & LCM

TIME COMPLEXITY : O( log (a * b) )
```cpp
#include <cstdio>

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int __lcm(int a, int b) {
	return (a / __gcd(a * b) * b);
}
```

#### Reduce a fraction
```cpp
scanf("%d %d", &numerator, &denominator);
int lcm = __lcm(numerator, denominator);
printf("%d/%d\n", lcm/denominator, lcm/numberator);
```
