#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll inf = 1e10;

#define FOR(i, a, b) for (int i = a; i < b; i++)

int n, q;
int a, b;

int main() {
    int cs = 1;
    while (scanf("%d", &n) && n) {
        char s[105][25];
        ll dis[105][105];
        FOR(i, 0, 105) FOR (j, 0, 105) dis[i][j] = inf;
        FOR(i, 0, n) {
            scanf("%s", s[i]);
            FOR(k, 0, n) {
                scanf("%lld", &dis[i][k]);
                if (dis[i][k] == 0) dis[i][k] = inf;
            }
        }
        FOR(i, 0, n) if (dis[i][i] > 0) dis[i][i] = 0;
        FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) {
            if (dis[i][k] < inf && dis[k][j] < inf && dis[i][j] > dis[i][k] + dis[k][j]) {
                dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
        FOR(i, 0, n) FOR(j, 0, n) FOR(t, 0, n) {
            if (dis[i][t] < inf && dis[t][j] < inf && dis[t][t] < 0) {
                dis[i][j] = -inf;
            }
        }
        scanf("%d", &q);
        printf("Case #%d:\n", cs++);
        while (q--) {
            scanf("%d %d", &a, &b);
            if (dis[a][b] == -inf) puts("NEGATIVE CYCLE");
            else if (dis[a][b] == inf) {
                printf("%s-%s %s\n", s[a], s[b], "NOT REACHABLE");
            } else {
                printf("%s-%s %lld\n", s[a], s[b], dis[a][b]);
            }
        }
    }
    return 0;
}
