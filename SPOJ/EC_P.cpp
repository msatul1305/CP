#include <bits/stdc++.h>
using namespace std;

const int N = 705;

vector<int> G[N];
vector< pair<int, int> > ans;
int vis[N], tin[N], fn[N];
int timer;

void dfs(int v, int p = -1) {
    vis[v] = 1;
    fn[v] = tin[v] = timer++;
    for (int i : G[v]) {
        if (p == i) continue;
        if (vis[i]) {
            fn[v] = min(fn[v], tin[i]);
        } else {
            dfs(i, v);
            fn[v] = min(fn[v], fn[i]);
            if (fn[i] > tin[v]) {
                if (i < v)
                    ans.push_back({i, v});
                else
                    ans.push_back({v, i});
            }
        }
    }
}

void reset() {
    timer = 0;
    ans.clear();
    for (int i = 0; i < N; i++) G[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(tin, -1, sizeof(tin));
    memset(fn, -1, sizeof(fn));
}

int t, n, m;
int a, b;

int main() {
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        reset();
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            dfs(i);
        }
        sort(ans.begin(), ans.end());
        
        printf("Caso #%d\n", k);
        
        if (ans.size()) {
            printf("%d\n", ans.size());
            for (auto &it : ans)
                printf("%d %d\n", it.first, it.second);
        } else {
            printf("Sin bloqueos\n");
        }
    }
    return 0;
}
