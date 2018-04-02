#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e2;

vector< tuple<int, int, int> > G;

int n, m;
int d[maxn];

void bf(int x) {
	memset(d, inf, sizeof(int)*maxn);
	d[x] = 0;
	for(int i = 1; i < n; i++) {
		for(auto e : G) {
			int a, b, w;
			tie(a, b, w) = e;
			d[b] = min(d[b], d[a] + w);
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		G.emplace_back(a, b, w);
	}
	bf(1);
	return 0;
}
