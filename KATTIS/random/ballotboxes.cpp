#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int a[N];
int n, b;

int p(int x) {
	int cb = 0;
	for (int i = 0; i < n; i++)
		cb += (a[i]+x-1) / x;
	return (cb <= b);
}

int main() {
	while (cin >> n >> b && n != -1) {
		int lo = 1, hi = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i], hi = max(hi, a[i]);
		while (lo < hi) {
			int m = (lo + hi) >> 1;
			if (p(m))
				hi = m;
			else
				lo = m+1;
		}
		cout << lo << '\n';
	}
	return 0;
}
