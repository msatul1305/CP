#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll binexp(ll x, int n) {
    ll res = 1;
    while (n) {
        if (n&1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int t;
ll a, n;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> n;
        cout << binexp(a, n) << '\n';
    }
    return 0;
}

