#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 5;

vector<int> G[N];
int vis[N];

int n, m;

void dfs(int v = 1, int p = 0) {
    vis[v] = 1;
    for (int t : G[v]) {
        if (vis[t] && t != p) {
            cout << "NO" << endl;
            exit(0);
        }
        if (t != p)
            dfs(t, v);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs();
    for (int i = 2; i <= n; i++)
        if (!vis[i]) {
            cout << "NO" << endl;
            return 0;
        }
    puts("YES");
    return 0;
}
