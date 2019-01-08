#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

ll phi[N];

void getPHI() {
    phi[0] = 0, phi[1] = 1;
    for (int i = 2; i < N; i++) phi[i] = i - 1;
    for (int i = 2; i < N; i++)
        for (int j = 2*i; j < N; j += i)
            phi[j] -= phi[i];
    for (int i = 2; i < N; i++) phi[i] += phi[i - 1];
}

int t;
ll k;

int main() {
    getPHI();
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &k);
        int den = lower_bound(phi,  phi + N, k) - phi;
        int kth = k - phi[den - 1], num;
        for (num = 1; num < N; num++) {
            if (__gcd(num, den) == 1) --kth;
            if (!kth) break;
        }
        printf("%d/%d\n", num, den);
    }
    return 0;
}
