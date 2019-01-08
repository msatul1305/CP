#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;

int n, m, q, s;

int main() {
    while (scanf("%d %d %d %d", &n, &m, &q, &s) && n) {
        vector< pair<int, int> > G[n];
        priority_queue< pair<int,int> > Q;
        vector<bool> vis(n, 0);
        vector<int> dis(n, inf);
        for (int i = 0; i < m ; i++) {
            int fr, to, we;
            scanf("%d %d %d", &fr, &to, &we);
            G[fr].push_back({to, we});
        }
        dis[s] = 0;
        Q.push({0, s});
        while (!Q.empty()) {
            int f = Q.top().second; Q.pop();
            if (vis[f]) continue;
            vis[f] = true;
            for (auto x : G[f]) {
                int to = x.first, we = x.second;
                if (dis[f] + we < dis[to]) {
                    dis[to] = dis[f] + we;
                    Q.push({-dis[to], to});
                }
            }
        }
        while (q--) {
            int d;
            scanf("%d", &d);
            if (dis[d] != inf)
                printf("%d\n", dis[d]);
            else
                puts("Impossible");
        }
        puts("");
    }
    return 0;
}
