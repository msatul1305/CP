/*
*	Bottom up segment tree
*	0 based based indexing queries and modifications
*	root at 1
*/
const int maxn = 1e5 + 5;

int tree[2 * maxn], n;

void build() {
	for(int i = n-1; i > 0; i--) {
		tree[i] += tree[2*i] + tree[2*i + 1];
	}
}

void modify(int k, int v) {
	k += n;
	tree[k] = v;
	while(k > 1) {
		tree[k/2] = tree[k] + tree[k^1];
		k /= 2;
	}
}

int query(int l, int r) {
	l += n, r += n;
	int sum = 0;
	while(l <= r) {
		if(l%2 == 1) sum += tree[l++];
		if(r%2 == 0) sum += tree[r--];
		l /= 2, r /= 2;
	}
	return sum;
}
