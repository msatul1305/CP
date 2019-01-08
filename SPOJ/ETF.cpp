#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll res = n;
        for (int i = 2; i*i <= n; i++) {
            if (n%i == 0) {
                while (n%i == 0) n /= i;
                res -= res/i;
            }
        }
        if (n > 1) res -= res/n;
        printf("%d\n", res);
    }
    return 0;
}
