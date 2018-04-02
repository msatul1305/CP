#include <bits/stdc++.h>
using namespace std;
//O(n + mlogm)

const int inf = 0x3f3f3f3f;

vector< pair<int, int> > G[1001];
priority_queue< pair<int, int> > Q;

int n, m;
int d[1001];
bool vis[1001];

void dijkstra(int k) {
	for(int i = 1; i <= n; i++)
		d[i] = inf;
	d[k] = 0;
	Q.push({0, k});
	while(!Q.empty()) {
		int f = Q.top().second; Q.pop();
		for(auto i : G[f]) {
			int t = i.first, w = i.second;
			if(d[t] > d[f] + w && !vis[t]) {
				vis[t] = 1;
				d[t] = d[f] + w;
				Q.push({-d[t], t});
			}
		}
	}
}

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	dijkstra(1);	
	return 0;
}
