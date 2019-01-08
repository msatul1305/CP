#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n, m;

ll dis[N];
int vis[N];
vector<pair<int, int>> G[N];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("in.txt", "r", stdin);
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  priority_queue<pair<ll, pair<int, int>>> pq;
  int maxE = 0;
  pq.push({0, {1, 0}});
  while(!pq.empty()) {
    auto f = pq.top(); pq.pop();
    ll dis = f.first;
    int u = f.second.first, pw = f.second.second;
    vis[u] = 1;
    maxE = max(pw, maxE);
    if (u == n)
      break;
    for (auto &x : G[u]) {
      int v = x.first, w = x.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!vis[v])
          pq.push({-dis[v], x});
      }
    }
  }
  cout << maxE << "\n" << dis[n] << endl;
  cout << ans << '\n';
  return 0;
}
