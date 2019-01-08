#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;

int n, m, q;
int fr, to, w;

int main() {
    while (scanf("%d %d %d", &n, &m, &q) && n != 0) {
        int dis[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) dis[i][j] = 0;
                else dis[i][j] = inf;
            }
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &fr, &to, &w);
            dis[fr][to] = min(dis[fr][to], w);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][k] < inf && dis[k][j] < inf)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int t = 0; t < n; t++) {
                    if (dis[t][t] < 0 && dis[i][t] < inf && dis[t][j] < inf)
                        dis[i][j] = -inf;
                }
            }
        }
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &fr, &to);
            int ans = dis[fr][to];
            if (ans == inf)
                puts("Impossible");
            else if (ans == -inf)
                puts("-Infinity");
            else
                printf("%d\n", ans);
        }
        puts("");
    }
    return 0;
}
