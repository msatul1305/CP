//incomplete
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;

int idx[N];
char per[N][35], igr[100];
char s[N][50];

bool mycmp(const char *a, const char *b) {
    int len_a = strlen(a), len_b = strlen(b);
    int len = min(len_a, len_b);
    for (int i = 0; i < len; i++) {
        if (a[i] > b[i]) return true;
        else if (b[i] > a[i]) return false;
    }
    if (len_a < len_b) return false;
    return true;
}

bool cmp(int a, int b) {
    return mycmp(s[a], s[b]);
}

char getC(char x) {
    if (x == 'l') return '0';
    if (x == 'm') return '1';
    if (x == 'u') return '2';
}

int t, n;

int main() {
  //freopen("in.txt", "r", stdin);
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
            char cur[105] = {0}; int p = 0;
            scanf("%[^:]: ", per[i]);
            scanf("%[^ ] ", cur);
            scanf("%[^\n]\n", igr);
            for (int j = 0; cur[j] != '\0'; j++) {
                if (j == 0 || cur[j - 1] == '-') {
                    s[i][p++] = getC(cur[j]);
                }
            }
            reverse(s[i], s[i] + p);
        }
        sort(idx, idx + n, cmp);
        for (int i = 0; i < n; i++)
            printf("%s\n", per[idx[i]]);
        puts("==============================");
        memset(per, 0, sizeof(per));
        memset(s, 0, sizeof(s));
    }
    return 0;
}
