#include <bits/stdc++.h>
using namespace std;

const int N = 2505;

const int ru[] = {0, 0, 1, -1};
const int cu[] = {-1, 1, 0, 0};
const char dir[] = {'L', 'R', 'D', 'U'};

void getN(int &a, int &b, char c) {
    for (int i = 0; i < 4; i++) {
        if (c == dir[i]) {
            a = ru[i], b = cu[i];
            return;
        }
    }
}

char getE(int a, int b) {
    for (int i = 0; i < 4; i++) {
        if (a == ru[i] && b == cu[i]) {
            return dir[i];
        }
    }
}

int n, m;
char mat[N][N], vis[N][N], p[N][N];

bool ok(int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < m)
        return true;
    return false;
}

void bfs(int r, int c) {
    queue< pair<int, int> > Q;
    Q.push({r, c});
    p[r][c] = '0';
    vis[r][c] = 1;
    while (!Q.empty()) {
        r = Q.front().first, c = Q.front().second; Q.pop();
        if (mat[r][c] == 'B') {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int rx = r + ru[i], cx = c + cu[i];
            if (ok(rx, cx) && mat[rx][cx] != '#' && !vis[rx][cx]) {
                Q.push({rx, cx});
                p[rx][cx] = getE(-1*ru[i], -1*cu[i]);
                vis[rx][cx] = 1;
            }
        }
    }
    if (mat[r][c] != 'B') {
        puts("NO");
        return;
    }
    string ans;
    while (mat[r][c] != 'A') {
        int x, y;
        getN(x, y, p[r][c]);
        ans.push_back(getE(-1*x, -1*y));
        r += x, c += y;
    }
    reverse(ans.begin(), ans.end());
    puts("YES");
    printf("%d\n", (int)ans.size());
    puts(ans.c_str());
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", mat[i]);
    int f = 1;
    for (int i = 0; i < n && f; i++) {
        for (int j = 0; j < m && f; j++) {
            if (mat[i][j] == 'A') {
                bfs(i, j);
                f = 0;
            }
        }
    }
    return 0;
}
