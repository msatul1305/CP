#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int t;

int main() {
    while (scanf("%d %d", &n, &m) && n) {
        unordered_set<int> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            if (s.find(t) == s.end()) {
                s.insert(t);
            } else {
                ++ans;
            }
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &t);
            if (s.find(t) == s.end()) {
                s.insert(t);
            } else {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
