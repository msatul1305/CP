#include <bits/stdc++.h>
using namespace std;

const int R[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int C[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int r, c, cs, ans;

char B[51][51];
bool vis[51][51];

bool check(int p, int q) {
	if(p >= 0 && p < r && q >= 0 && q < c) return true;
}

void dfs(int x, int y, int d) {
	ans = max(ans, d);
	for(int i = 0; i < 8; i++) {
		int p = x + R[i], q = y + C[i];
		if(check(p, q) && !vis[p][q] && B[x][y]+1 == B[p][q]) {
				vis[x][y] = 1;
				dfs(p, q, d + 1);
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	while(1) {
		cin >> r >> c;
		if(r == 0) return 0;
		ans = 0;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				cin >> B[i][j];
				vis[i][j] = 0;
			}
		}
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(B[i][j] == 'A') {
					dfs(i, j, 1);
				}
			}
		}
		cout << "Case " << ++cs << ": " << ans <<'\n';
	}
	return 0;
}
