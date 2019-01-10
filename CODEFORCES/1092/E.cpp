#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 5;

vector<int> G[N];
int n, m;
int vis[N], dis[N], par[N];

int maxv, maxd;

void dfs(int u, int p) {
	vis[u] = 1;
	par[u] = p;
	if (p != 0)
		dis[u] += dis[p] + 1;
	if (maxd < dis[u]) {
		maxd = dis[u];
		maxv = u;
	}
	for (int v : G[u]) {
		if (!vis[v]) {
			dfs(v, u);
		}
	}
}

void clear() {
	for (int i = 0; i <= n; i++)
		vis[i] = dis[i] = par[i] = 0;
}

void getDiameter(int i) {
	clear();
	maxv = i;
	maxd = 0;
	dfs(i, 0);
	clear();
	maxd = 0; //diameter
	dfs(maxv, 0);
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> centers;
	int maxD = 0, maxDc = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			getDiameter(i);
			int center = maxv;
			while (dis[center] > maxd/2) {
				center = par[center];
			}
			if (maxd > maxD) {
				maxDc = centers.size();
				maxD = maxd;
			}
			centers.push_back(center);
		}
	}
	for (int i = 0; i < (int)centers.size(); i++) {
		if (i != maxDc) {
			int u = centers[maxDc];
			int v = centers[i];
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	getDiameter(1);
	cout << maxd << '\n';
	for (int i = 0; i < (int)centers.size(); i++) {
		if (i != maxDc) {
			int u = centers[maxDc];
			int v = centers[i];
			cout << v << " " << u << '\n';
		}
	}
	return 0;
}
