
# Modular Exponentiation

To find  a^b^ % mod

Time Complexity : **O(log~2~a)**

```cpp
Long exp(Long x, Long n) {  
	if(n==0) return 1;
	if(n==1) return x;
	if(n%2==0) return exp((x*x) % mod, n / 2);
	if(n%2==1) return (x * exp((x*x) % mod, n / 2)) % mod;
}
```

