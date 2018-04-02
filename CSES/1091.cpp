#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q;
int tmp;
multiset<int> prices;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		prices.insert(tmp);
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", &q);
		auto x = prices.lower_bound(q);
		if(x == prices.begin() && *x != q) {
			puts("-1");
			continue;
		} else if(x == prices.end()) {
			--x;
			if(*x <= q) {
				printf("%d\n", *x);
				continue;
			} else {
				puts("-1");
				continue;
			}
		}
		if(q != *x)
			--x;
		printf("%d\n", *x);
		prices.erase(x);
	}
	return 0;
}
