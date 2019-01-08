#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10000000;

int p[N];

bool isprime(int x) {
    if (x % 2 == 0 && x != 2) return false;
    for (int i = 3; 1LL*i*i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int t, n;

int main() {
    for (ll i = 1; i <= 3170; i++) {
        for (ll j = 1; j <= 60; j++) {
            ll cur = pow(i, 2) + pow(j, 4);
            if (cur < N && isprime(cur)) p[cur] = 1;
        }
    }
    for (int i = 1; i < N; i++) p[i] += p[i - 1];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", p[n]);
    }
    return 0;
}
