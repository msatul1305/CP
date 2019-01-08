#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> G[10005];
int c[10005];

int component = 0;

void dfs(int u, int p) {
	component++;
	c[u] = !c[p];
	for (int v : G[u]) {
		if (c[v] == -1) {
			dfs(v, u);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	memset(c, -1, sizeof(c));
	c[0] = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int imp = 0;
	for (int i = 1; i <= n; i++) {
		component = 0;
		if (c[i] == -1)
			dfs(i, 0);
		if (component == 1) {
			imp = 1;
			break;
		}
	}
	if (imp) {
		cout << "Impossible\n";
	} else {
		for (int i = 1; i <= n; i++) {
			if (c[i] == 1) {
				cout << "pub ";
			} else {
				cout << "house ";
			}
		}
	}
	cout << '\n';
	return 0;
}
