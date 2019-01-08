#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

char s[N];
ll dp[N];
int f[256];

int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int sz = strlen(s + 1);
        dp[0] = 1;
        for (int i = 1; i <= sz; i++) {
            dp[i] = (2 * dp[i - 1]) % mod;
            if (f[s[i]] != 0) {
                dp[i] = (dp[i] - dp[f[s[i]] - 1] + mod) % mod;
            }
            f[s[i]] = i;
        }
        printf("%d\n", dp[sz]);
        memset(f, 0, sizeof(f));
    }
    return 0;
}
