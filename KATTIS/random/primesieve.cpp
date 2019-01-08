#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e8 + 1;

bitset<N> notprime;

ll n, cnt;

void sieve() {
    notprime[1] = 1;
    for (int i = 2; i <= n; i++) {
        if ((i == 2 || i&1) && !notprime[i]) {
            ++cnt;
            for (int k = i+i; k <= n; k += i) {
                notprime[k] = 1;
            }
        }
    }
}

int q, num;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%lld %d", &n, &q);
    sieve();
    printf("%lld\n", cnt);
    while (q--) {
        scanf("%d", &num);
        printf("%d\n", !notprime[num]);
    }
    return 0;
}
