#include <bits/stdc++.h>
using namespace std;

char am[105][105];
bool vis[105][105] = {0};

int m, n;
int ans;

const int R[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int C[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int p, int q) {
	for(int k = 0; k < 8; k += 1) {
		int r = p + R[k], c = q + C[k];
		if((r >= 0 && r <= m) && (c >= 0 && c <= n) && !vis[r][c] && am[r][c] == '#') {
			vis[r][c] = 1;
			dfs(r, c);
		}
	}
}

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i += 1) {
		for(int j = 0; j < n; j += 1) {
			scanf(" %c", &am[i][j]);
		}
	}
	for(int i = 0; i < m; i += 1) {
		for(int j = 0; j < n; j += 1) {
			if(!vis[i][j] && am[i][j] == '#') {
				vis[i][j] = 1;
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
