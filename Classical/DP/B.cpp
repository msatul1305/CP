#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x).size()

const int inf = 0x3f3f3f3f;

int c[55], ans[255];
int n, m;//needed no. and no. of denominations

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", c + i);
	}
	ans[0] = 1;
	for(int i = 0; i < m; i++) {
		for(int j = c[i]; j <= n; j++) {
			if(j - c[i] >= 0) {
				ans[j] += ans[j - c[i]];
			}
		}
	}
	printf("%d\n", ans[n]);
	return 0;
}
