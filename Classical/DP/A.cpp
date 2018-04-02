#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int c[55], ans[255];
int n, m;//needed no. and no. of denominations

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", c + i);
	}
	ans[0] = 0;
	for(int i = 1; i <= n; i++) {
		ans[i] = inf;
		for(int j = 0; j < m; j++) {
			if(i - c[j] >= 0) {
				ans[i] = min(ans[i], ans[i - c[j]] + 1);
			}
		}
	}
	printf("%d\n", ans[n]);
	return 0;
}
