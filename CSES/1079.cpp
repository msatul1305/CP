#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const int M = 1e6 + 5;

ll fac[M], inv[M];
/*
ll inv(ll a) {
    ll n = mod - 2;
    ll res = 1;
    while (n) {
        if (n&1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}*/

void calc() {
    fac[0] = 1;
    for (int i = 1; i < M; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    inv[1] = 1;
    for (int i = 2; i < M; i++)
        inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
}

int t;

int main() {
    calc();
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        assert(k <= n);
        cout << (fac[n] * (inv[fac[k]] * inv[fac[n - k]] + mod) % mod) % mod << '\n';
    }
    return 0;
}

