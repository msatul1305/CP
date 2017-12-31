#include <bits/stdc++.h>
using namespace std;

int read() {
	int x=0; char ch=getchar_unlocked();
	while(ch<'0' || ch>'9') ch=getchar_unlocked();
	while(ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar_unlocked(); }
	return x;
}

int main() {
	int t = read();
	while(t--) {
		int n = read(), u = read();
		vector<int> x(n + 1, 0);
		while(u--) {
			int l = read(), r = read(), v = read();
			x[l] += v, x[r + 1] -= v;
		}
		for(int i = 1; i < n; i++) {
			x[i] += x[i - 1];
		}
		int q = read();
		while(q--) {
			u = read();
			printf("%d\n", x[u]);
		}
	}
}
