#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll binexp(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n&1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll t, k;

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &k);
        ll ans;
        if (k <= 4)
            ans = k;
        else if (k % 3 == 0)
            ans = binexp(3, k/3);
        else if (k % 3 == 1)
            ans = 2 * 2 * binexp(3, k/3 - 1);
        else
            ans = 2 * binexp(3, k/3);
        printf("%lld\n", ans % mod);
    }
    return 0;
}
