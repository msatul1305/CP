#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int read() {
	bool neg = false;
	int x = 0; char ch = getchar_unlocked();
	while(ch < '0' || ch > '9') { if(ch == '-') neg = true; ch = getchar_unlocked(); }
	while(ch >= '0' && ch <= '9') { x = x*10+ch-48; ch = getchar_unlocked(); }
	if(neg) return -x;
	return x;
}

void write(int x) {
	if(x < 0) { x = abs(x); putchar_unlocked('-'); }
	if(x > 9) write(x/10);
	putchar_unlocked(x%10+48);
}

int n, q, bz, rans;

struct Q {
	int l, r, ix;
	bool operator<(const Q &rhs) {
		if(l/bz != rhs.l/bz) {
			return l/bz < rhs.l/bz;
		}
		return r < rhs.r;
	}
};

int num[int(3e4 + 5)];
int cnt[int(1e6 + 5)];
Q que[int(2e5 + 5)];
int ans[int(2e5 + 5)];

void add(int pos) {
	cnt[num[pos]]++;
	if(cnt[num[pos]] == 1) rans++;
}

void rem(int pos) {
	cnt[num[pos]]--;
	if(cnt[num[pos]] == 0) rans--;
}

int main() {
	n = read();
	for(int i = 0; i < n; i++)
		num[i] = read();
	
	bz = sqrt(n);
	
	q = read();
	for(int i = 0; i < q; i++)
		que[i].l = read(), que[i].r = read(), que[i].ix = i;
	
	sort(que, que + q);
	
	int curL = 0, curR = 0;
	
	for(int i = 0; i < q; i++) {
		int L = que[i].l - 1, R = que[i].r - 1;

		while(curL < L) {
			rem(curL);
			curL++;
		}
		while(curL > L) {
			add(--curL);
		}
		while(curR < R) {
			if(curR == 0) add(curR);
			add(++curR);
		}
		while(curR > R) {
			rem(curR);
			curR--;
		}

		ans[que[i].ix] = rans;
	}
	
	for(int i = 0; i < q; i++) {
		write(ans[i]);
		putchar_unlocked('\n');
	}
	
	return 0;
}
