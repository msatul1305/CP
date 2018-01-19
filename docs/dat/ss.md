## GENERATING SUBSETS

(1 << 4) = 4 digits 0 to 15  
(1 << 3) = 3 digits 0 to 7


### USING BITMASK
```cpp
void search() {
	int n = 4;
	for(int i = 0; i < (1 << n); i++) {
		vector<int> v;
		for(int j = 0; j < n; j++) {
			if(i & (1<<j))
				v.push_back(j);
		}
		//process(v);
	}
}
```

### USING RECURSION
```cpp
int n = 4;

void search(int k) {
	if(k == n) {
		//process(v);
	}
	else {
		search(k + 1);
		v.push_back(k);
		search(k + 1);
		v.pop_back();
	}
}
```
