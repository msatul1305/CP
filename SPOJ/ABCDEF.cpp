#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e2 + 5;

ll a[N], ans;
int n;
unordered_map <ll, ll> mp;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ++mp[a[i] * a[j] + a[k]];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) if (a[i] != 0) {
                auto s = mp.find(a[i] * (a[j] + a[k]));
                if (s != mp.end())
                    ans += s->second;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
