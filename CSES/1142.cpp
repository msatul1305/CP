#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n, f[N];
ll ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);
    vector<int> c;
    for (int i = 0; i <= n; i++) {
        while (!c.empty() && f[i] <= f[c.back()]) {
            int cur = f[c.back()];
            c.pop_back();
            int r = i, l = c.empty() ? -1 : c.back();
            ans = max(ans, 1LL * cur * (r - l - 1));
        }
        c.push_back(i);
    }
    printf("%lld\n", ans);
    return 0;
}
