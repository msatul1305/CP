#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

ll fac() {
    int ret = 0;
    ll cur = 2;
    while (cur*cur <= n) {
        if (n % cur == 0) {
            ret++;
            while (n % cur == 0)
                n /= cur;
        } else {
            cur++;
        }
    }
    return ret + 1;
}

int main() {
    scanf("%lld", &n);
    printf("%lld\n", fac());
    return 0;
}
