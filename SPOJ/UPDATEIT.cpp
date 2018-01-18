#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;

int ar[maxn];

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n, u; scanf("%d%d", &n, &u);
		while(u--) {
			int l, r, v; scanf("%d%d%d", &l, &r, &v);
			ar[l] += v, ar[r + 1] -= v;
		}
		for(int i = 1; i < n; i++) ar[i] += ar[i-1];
		scanf("%d", &u);
		while(u--) {
			int q; scanf("%d", &q);
			printf("%d\n", ar[q]);
		}
		memset(ar, 0, sizeof(ar));
	}
	return 0;
}
