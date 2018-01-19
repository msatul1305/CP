
## Partial Sums
## prefix sum array : 
```cpp
for(int i = 1; i < sz(ar); i++)
	ar[i] += ar[i - 1];
```
Sum of elements in [L ~ R] = ar[R] - ar[L - 1]

## suffix sum array :
```cpp
for(int i = 1; i < sz(ar); i++)
	ar[i] += ar[i - 1];
```
Sum of elements in [L ~ R] = ar[L] - ar[R + 1]

## difference array : 

```cpp
for(int i = 1; i < sz(ar); i++)
	ar[i] -= ar[i - 1];
```
#### Range Updates/Point Updates  @ O( 1 ): 
update[L ~ R] (Adding X) :  
DA[L] += X ;  DA[R + 1] -= X ;


