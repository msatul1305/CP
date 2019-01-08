#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

int ru[] = {0, -1, 0, 1};
int cu[] = {-1, 0, 1, 0};

char G[N][N];
int comp[N][N];
int R, C, q;

int cur, Bcur, Dcur;
void dfs(int a, int b) {
    comp[a][b] = cur;
    for (int i = 0; i < 4; i++) {
        int r = a + ru[i], c = b + cu[i];
        if (r < R && c < C && r >= 0 && c >= 0 && !comp[r][c] && G[a][b] == G[r][c])
            dfs(r, c);
    }
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
        scanf("%s", G[i]);
    scanf("%d", &q);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!comp[i][j]) {
                if (G[i][j] == '0') {
                    cur = ++Bcur;
                } else {
                    cur = --Dcur;
                }
                dfs(i, j);
            }
        }
    }
    while (q--) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--, r2--, c1--, c2--;
        if (comp[r1][c1] == comp[r2][c2] && comp[r1][c1] > 0)
            puts("binary");
        else if (comp[r1][c1] == comp[r2][c2] && comp[r1][c1] < 0)
            puts("decimal");
        else
            puts("neither");
    }
    return 0;
}
