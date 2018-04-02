const int maxn = 5e4 + 5;

struct node {
	//node data here
};

Long ar[maxn];
node tree[4 * maxn];  //2*2^(logn)−1 . !!THINK!!

node combine(node l, node r) {
	node ret;
	
	//combine function
	
	return ret;
}

node make(Long d) {
	node ret;
	
	//create node
	
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
	if(l > r) return make(-16000);// MODIFY THIS AS REQUIRED
	if(l == tl && r == tr) return tree[v];
	int tm = (tl + tr)>>1;
	return combine(query(v<<1, tl, tm, l, min(r, tm)),
				   query(v<<1|1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int p, int val) {
	if(tl == tr) tree[v] = make(val);
	else {
		int tm = (tl + tr)>>1;
		if(p <= tm)
			update(v<<1, tl, tm, p, val);
		else
			update(v<<1|1, tm+1, tr, p, val);
		tree[v] = combine(tree[v<<1], tree[v<<1|1]);
	}
} 
