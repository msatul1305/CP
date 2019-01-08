#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int read() {
    bool neg = false;
    int x = 0; char ch = getchar_unlocked();
    while(ch < '0' || ch > '9') { if(ch == '-') neg = true; ch = getchar_unlocked(); }
    while(ch >= '0' && ch <= '9') { x = x*10+ch-48; ch = getchar_unlocked(); }
    if(neg) return -x;
    return x;
}

void write(ll x) {
    if(x < 0) { x = -x; putchar_unlocked('-'); }
    if(x > 9) write(x/10);
    putchar_unlocked(x%10+48);
}

int n;
int a[N];

ll p(int k) {
	ll cost = 0;
	for (int i = 0; i < n; i++)
		cost += abs(k - a[i]);
	return cost;
}

int main () {
	n = read();
	int lo = 0, hi = 0;
	for (int i = 0; i < n; i++)
		a[i] = read(), hi = max(hi, a[i]);
	while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		if (p(mid) < p(mid + 1)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	write(p(lo));
	return 0;
}
