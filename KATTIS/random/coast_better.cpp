#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char mp[1005][1005], vis[1005][1005];
int n, m;
int ans;

int ur[] = {0, -1, 0, 1}, uc[] = {-1, 0, 1, 0};//LURD

bool withinLimits(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int r = x + ur[i], c = y + uc[i];
        if (withinLimits(r, c)) {
            if (!vis[r][c] && mp[r][c] == '0')
                dfs(r, c);
            else if (mp[r][c] == '1')
                ans++;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", mp[i]);
    for (int i = 0; i < n; i++) {
        if (!vis[i][0] && mp[i][0] == '0')
            dfs(i, 0);
        if (mp[i][0] == '1')
            ans++;
        if (!vis[i][m-1] && mp[i][m-1] == '0')
            dfs(i, m-1);
        if (mp[i][m-1] == '1')
            ans++;
    }
    for (int i = 0; i < m; i++) {
        if (!vis[0][i] && mp[0][i] == '0')
            dfs(0, i);
        if (mp[0][i] == '1')
            ans++;
        if (!vis[n-1][i] && mp[n-1][i] == '0')
            dfs(n-1, i);
        if (mp[n-1][i] == '1')
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
