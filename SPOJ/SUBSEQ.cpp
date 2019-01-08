#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n, c;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        unordered_map<ll, int> ps;
        ps[0] = 1;
        ll s = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &c);
            s += c;
            auto f = ps.find(s);
            if (f == ps.end()) {
                ps[s] = 1;
            } else {
                ps[s] += 1;
            }
            if ((f = ps.find(s - 47)) != ps.end())
                ans += f->second;
        }
        printf("%d\n", ans);
    }
    return 0;
}
