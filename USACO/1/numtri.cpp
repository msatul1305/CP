/*
ID: <hidden>
TASK: numtri
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

int dp[N][N];

int n, ans, cur;

/* RECUSIVE SOLUTION
void solve(int r, int c, int sum, int dep) {
	if(dep == n) {
		ans = max(ans, sum + tri[r][c]);
		return;
	}

	if(tri[r + 1][c] != -1) {
		solve(r + 1, c, sum + tri[r][c], dep + 1);
	}
	if(tri[r + 1][c + 1] != -1) {
		solve(r + 1, c + 1, sum + tri[r][c], dep + 1);
	}
}
*/

int main() {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			scanf("%d", &cur);
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + cur;
		}
	}
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
