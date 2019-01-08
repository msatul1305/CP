#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a, b;

int main() {
    scanf("%d", &t);
    for (int it = 1; it <= t; it++) {
        scanf("%d %d", &n, &m);
        bool ans = true;
        vector<int> G[n + 1];
        vector<int> vis(n + 1, -1);
        
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for (int k = 1; k <= n; k++) if (vis[k] == -1) {
            queue<int> Q;
            Q.push(k);
            vis[k] = 1;
            
            while (!Q.empty()) {
                int f = Q.front(); Q.pop();
                for (int i : G[f]) {
                    if (vis[i] == -1) {
                        vis[i] = vis[f] == 1 ? 2 : 1;
                        Q.push(i);
                    } else if (vis[f] == vis[i]) {
                        ans = false;
                    }

                }
            }
        }
        
        printf("Scenario #%d:\n", it);

        if (ans) {
            printf("No suspicious bugs found!\n");
        } else {
            printf("Suspicious bugs found!\n");
        }
    }
    return 0;
}
