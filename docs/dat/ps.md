
## Partial Sums
## prefix sum array : 
```cpp
for(int i = 1; i < sz(ar); i++)
	ar[i] += ar[i - 1];
```
|                  |   |   |   |   |   |   |   |
|:----------------:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| Array | 1 | 8 | 5 | 6 | 9 | 4 | 2 |
|Prefix Sum Array | 1 | 9 | 14 | 20 | 29 | 33 | 35 |

Sum of elements in [L ~ R] = R - ar[L - 1]

## suffix sum array :
```cpp
for(int i = 1; i < sz(ar); i++)
	ar[i] += ar[i - 1];
```
|                  |   |   |   |   |   |   |   |
|:----------------:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| Array | 1 | 8 | 5 | 6 | 9 | 4 | 2 |
|Prefix Sum Array | 35 | 34 | 26 | 21 | 15 | 6 | 2 |

Sum of elements in [L ~ R] = L - ar[R + 1]

## difference array : 

```cpp
for(int i = 1; i < sz(ar); i++)
	ar[i] -= ar[i - 1];
```
|                  |   |   |   |   |   |   |   |
|:----------------:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| Array            | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| Difference Array | 1 | 1 | 2 | 2 | 3 | 3 | 4 |

#### Range Updates/Point Updates  @ O( 1 ): 
update[L ~ R] (Adding X) :  
DA[L] += X ;  DA[R + 1] -= X ;


