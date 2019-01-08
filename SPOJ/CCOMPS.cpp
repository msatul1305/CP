#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100005;

vector<int> G[N];
bool vis[N];

void dfs(int k) {
    vis[k] = 1;
    for (int i : G[k]) {
        if (!vis[i])
            dfs(i);
    }
}

int n, m, ans;
int a, b;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++ans;
            dfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
