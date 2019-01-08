#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

const int N = 3e4 + 5;

vector<int> seg[N << 1];

int n, q;
int ans;

void build() {
    for (int i = n - 1; i >= 1; i--)
        merge(all(seg[2*i]), all(seg[2*i + 1]), back_inserter(seg[i]));
}

int get(int x, int k) {
    int t = seg[x].end() - upper_bound(all(seg[x]), k);
    return t;
}

int query(int l, int r, int k) {
    int cur = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1)
            cur += get(l++, k);
        if (r % 2 == 0)
            cur += get(r--, k);
    }
    return cur;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        seg[n + i].push_back(c);
    }
    build();
    scanf("%d", &q);
    while(q--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a ^= ans, b ^= ans, c ^= ans;
        if (a < 1) a = 1;
        if (b > n) b = n;
        ans = a > b ? 0 : query(a - 1, b - 1, c);
        printf("%d\n", ans);
    }
    return 0;
}
