## Fast I/0

```cpp
int read() {
	int x = 0; char ch = getchar_unlocked();
	while(ch < '0' || ch > '9') ch = getchar_unlocked();
	while(ch >= '0' && ch <='9') x = x * 10 + ch - '0', ch = getchar_unlocked();
	return x;
}

void write(int x) {
	if(x>9) write(x/10);
	putchar_unlocked(x%10+48);
}
```

