#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

vector<int> G[N];
ll totsum, rootsum;
ll sum[N], subsum[N], rootat[N];
ll ans;

int n;

void dfs(int u, int p, int dis) {
	rootsum += dis * sum[u];
	subsum[u] += sum[u];
	for (int v : G[u]) {
		if (v != p) {
			dfs(v, u, dis+1);
			subsum[u] += subsum[v];
		}
	}
}

void dfs2(int u, int p) {
	if (p != 0) {
		rootat[u] = rootat[p] + (totsum - subsum[u]) - subsum[u];
		ans = max(ans, rootat[u]);
	}
	for (int v : G[u]) {
		if (v != p) {
			dfs2(v, u);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		totsum += sum[i];
	}
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 0, 0);
	ans = rootsum;
	rootat[1] = rootsum;
	dfs2(1, 0);
	cout << ans << '\n';
	return 0;
}
