#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
//bottom up
int tree[maxn], n;

void build() {
	for(int i = n - 1; i > 0; i--)
		tree[i] = min(tree[2*i], tree[2*i + 1]);
}

int query(int l, int r) {
	l += n, r += n;
	int ans = INT_MAX;
	while(l <= r) {
		if(l % 2 == 1) ans = min(ans, tree[l++]);
		if(r % 2 == 0) ans = min(ans, tree[r--]);
		l /= 2, r /= 2;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", tree + n + i);
	build();
	int q; scanf("%d", &q);
	while(q--) {
		int l, r; scanf("%d %d", &l, &r);
		printf("%d\n", query(l, r));
	}
}
