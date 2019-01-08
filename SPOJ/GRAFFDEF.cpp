#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

vector<int> G[N];
vector< pair<int, int> > b;
int vis[N], par[N];
int st[N], fn[N];
ll d[N], rd[N];

int TIME = 0;

void fix(int v) {
    vis[v] = 1;
    for (int u : G[v]) {
        if (!vis[u]) {
            par[u] = v;
            fix(u);
            d[v] += d[u] + 1;
        }
    }
}

void bfs(int s) {
    queue< pair<int, int> > Q;
    Q.push({s, 0});
    vis[s] = 1;
    while (!Q.empty()) {
        int f = Q.front().first, c = Q.front().second; Q.pop();
        rd[f] = c;
        for (int to : G[f]) {
            if (!vis[f]) {
                vis[f] = 1;
                Q.push({to, c + 1});
            }
        }
    }
}

void get(int v, int p = -1) {
    vis[v] = 1;
    st[v] = TIME++;
    fn[v] = st[v];
    for (int u : G[v]) {
        if (u == p) continue;
        if (!vis[u]) {
            get(u, v);
            fn[v] = min(fn[v], fn[u]);
            if (st[v] < fn[u]) {
                b.push_back({v, u});
            }
        } else {
            fn[v] = min(fn[v], st[u]);
        }
    }
}

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    get(1);
    memset(vis, 0, sizeof(vis));
    fix(1);
    memset(vis, 0, sizeof(vis));
    bfs(1);
    ll ans = 0;
    for (auto &i : b) {
        ll k = (rd[i.first] > rd[i.second] ? d[i.first] : d[i.second]) + 1;
        ans += k * (n - k);
    }
    printf("%.9lf\n", 1.0 * ans / (1LL * n * (n - 1) / 2));
    return 0;
}
