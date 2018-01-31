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

## Union returning size of the group.
```cpp
class UF {
    private:
        vector<int> L, S;
    public:
        UF(int n) {
            L.resize(n + 1), S.resize(n + 1);
            for(int i = 0; i <= n; i++)
                L[i] = i , S[i] = 1;
        }
        int Find(int a) {
            return a == L[a] ? a : L[a] = Find(L[a]);
        }
        int Union(int a, int b) {
            int x = Find(a), y = Find(b);
            if(x != y) {
                L[x] = y;
                S[y] += S[x];
            }
            return S[y];
        }
};
```
