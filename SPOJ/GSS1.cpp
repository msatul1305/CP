//TOP DOWN SEGTREE
#include <cstdio>
#include <algorithm>
#include <climits>

#define Long long long

using namespace std;

const int maxn = 5e4 + 5;

struct node {
	Long mxsum, sum, prefix, suffix;
};

Long ar[maxn];
node tree[4 * maxn];

node combine(node l, node r) {
	node ret;
	ret.prefix = max(l.sum + r.prefix, l.prefix);
	ret.suffix = max(r.sum + l.suffix, r.suffix);
	ret.sum = l.sum + r.sum;
	ret.mxsum = max(max(l.mxsum, r.mxsum), l.suffix + r.prefix);
	return ret;
}

node make(Long d) {
	node ret;
	ret.mxsum = ret.sum = ret.prefix = ret.suffix = d;
	return ret;
}


void build(int v, int l, int r) {
	if(l == r) tree[v] = make(ar[l]);
	else {
		int m = (l + r)>>1;
		build(v<<1, l, m);
		build(v<<1|1, m+1, r);
		tree[v] = combine(tree[v<<1], tree[v<<1|1]);
	}
}

node query(int v, int tl, int tr, int l, int r) {
	if(l > r) return make(-16000);
	if(l == tl && r == tr) return tree[v];
	int tm = (tl + tr)>>1;
	return combine(query(v<<1, tl, tm, l, min(r, tm)),
				   query(v<<1|1, tm+1, tr, max(l, tm+1), r));
}

int n, q;
int u, v;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", ar + i);
	}
	build(1, 0, n - 1);
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &u, &v);
		printf("%lld\n", query(1, 0, n - 1, --u, --v).mxsum);
	}
	return 0;
}
