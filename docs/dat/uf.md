# UNION-FIND

## IMPLEMENTATION
```cpp
int Find(int x) {
	while(x != L[x]) x = L[x];
	return x;
}

void Union(int x, int y) {
	L[Find(x)] = Find(y);
}
```  

## WITH PATH-COMPRESSION
backtracks to x and reroute all
the links to the root  
```cpp
int Find(int x) {
	return (x == L[x]) ? x : (L[x] = Find[x]);
}

void Union(int x, int y) {
	L[Find(x)] = Find(y);
}
```
