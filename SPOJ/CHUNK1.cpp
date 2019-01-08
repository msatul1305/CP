#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, a = 0;
        scanf("%d %d", &n, &m);
        int G[n + 1] = {0}, ans[n + 1] = {0};
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u != v)
                G[u]++;
        }
        for (int i = 1; i <= n; i++)
            if (G[i] == 0)
                ans[a++] = i;
        sort(ans, ans + a);
        for (int i = 0; i < a; i++)
            printf("%d%c", ans[i], " \n"[i == a-1]);
    }
    return 0;
}
