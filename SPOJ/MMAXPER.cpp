#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int dp[maxn][2];
int a[maxn], b[maxn];

int main() {
	//freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	scanf("%d%d", &a[0], &b[0]);
	dp[0][0] = a[0], dp[0][1] = b[0];
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		dp[i][0] = a[i] + max(dp[i-1][0] + abs(b[i-1] - b[i]),
							  dp[i-1][1] + abs(a[i-1] - b[i]));
		dp[i][1] = b[i] + max(dp[i-1][0] + abs(b[i-1] - a[i]),
							  dp[i-1][1] + abs(a[i-1] - a[i]));
	}
	printf("%d\n", max(dp[n-1][0], dp[n-1][1]));
	return 0;
}
