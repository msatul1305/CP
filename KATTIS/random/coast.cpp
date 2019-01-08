//FAILED APPROACH
//WHAT ABOUT BIGGER PONDS
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

bool pond(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int r = ur[i] + x, c = uc[i] + y;
        if (withinLimits(r, c) && mp[r][c] == '1') {
            cnt++;
        }
    }
    return (cnt == 4);
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int r = x + ur[i], c = y + uc[i];
        if (!withinLimits(r, c)) {
            ans++;
        } else if (mp[r][c] == '0' && !pond(r, c)) {
            if (r == 0 && c == 0)
                int x = 89;
            ans++;
        }
    }
    for (int i = 0; i < 4; i++) {
        int r = x + ur[i], c = y + uc[i];
        if (withinLimits(r, c) && !vis[r][c] && mp[r][c] == '1') {
            dfs(r, c);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", mp[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && mp[i][j] == '1')
                dfs(i, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}
