const int maxn = 1e3 + 5;

int tree[maxn], n = 5;

void update(int k, int x) {
	while(k <= n) {
		tree[k] += x;
		k += k&(-k);
	}
}

int sum(int r) {
	int s = 0;
	while(r >= 1) {
		s += tree[r];
		r -= r&(-r);
	}
	return s;
}

int rsum(int l,int r) {
	return (sum(r) - sum(l - 1));
}
