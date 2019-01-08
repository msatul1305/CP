#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<int> G[N];
int vis[N], fn[N], tin[N], ans[N];
int timer;

void dfs(int v, int p = -1) {
    vis[v] = 1;
    fn[v] = tin[v] = timer++;
    int des = 0;
        
    for (int to : G[v]) {
        if (to == p) continue;
        if (vis[to]) {
            fn[v] = min(fn[v], tin[to]);
        } else {
            dfs(to, v);
            fn[v] = min(fn[v], fn[to]);
            if (fn[to] >= tin[v] && p != -1)
                ans[v] = 1;
            ++des;
        }
    }
    
    if (p == -1 && des > 1)
        ans[v] = 1;
}

void reset() {
    for (int i = 0; i < N; i++) G[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(fn, -1, sizeof(fn));
    memset(tin, -1, sizeof(tin));
    memset(ans, 0, sizeof(ans));
    timer = 0;
}

int n, m;
int a, b;

int main() {
    while (scanf("%d %d", &n, &m)) {
        if (n == 0) break;
        reset();
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        printf("%d\n", accumulate(ans, ans + n + 1, 0));
    }
    return 0;
}
