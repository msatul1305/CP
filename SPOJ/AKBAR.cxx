#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n, r, m, x, y;
		scanf("%d%d%d", &n, &r, &m);
		vector<int> g[n + 1];
		vector<int> p(n + 1, 0);
		while(r--) {
			scanf("%d%d", &x, &y);
			g[y].push_back(x);
			g[x].push_back(y);
		}
		for(int i = 0; i < m; i++) {
			vector<bool> vis(n + 1, false);
			int c, s; scanf("%d%d", &c, &s);
			p[c]++;
			vis[c] = true;
			queue< pair<int, int> > q;
			q.push({c, s});
			while(!q.empty() && q.front().second) {
				int f = q.front().first;
				int d = q.front().second;
				q.pop();
				for(int i = 0; i < (int)g[f].size(); i++) {
					if(!vis[g[f][i]]) {
						vis[g[f][i]] = true, ++p[g[f][i]];
						q.push({g[f][i], d - 1});
					}
				}
			}
		}
		bool ans = true;
		for(int i = 1; i < (int)p.size(); i++) {
			if(p[i] != 1) {
				ans = false;
				break;
			}
		}
		ans ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
