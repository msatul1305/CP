#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        int n, q;
        scanf("%d %d", &n, &q);
        vector<int> v(2*n + 5);
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i + n]);
        for (int i = n-1; i >= 1; i--)
            v[i] = min(v[2*i], v[2*i + 1]);
        printf("Scenario #%d:\n", c);
        while (q--) {
            int a, b, ans = 0x3f3f3f3f;
            scanf("%d %d", &a, &b);
            for (a += n-1, b += n-1; a <= b; a /= 2, b /= 2) {
                if (a % 2 == 1) ans = min(v[a++], ans);
                if (b % 2 == 0) ans = min(v[b--], ans);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
