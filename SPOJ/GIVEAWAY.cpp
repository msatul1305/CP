#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

const int N = 5e5 + 5;

vector<int> seg[N << 1];
int ar[N];

int n, q;
int ans;

void build() {
    for (int i = n - 1; i >= 1; i--)
        merge(all(seg[2*i]), all(seg[2*i + 1]), back_inserter(seg[i]));
}

int get(int x, int k) {
    int t = seg[x].end() - lower_bound(all(seg[x]), k);
    return t;
}

void update(int x, int y, int k) {
    k += n;
    while (k > 0) {
        auto z = lower_bound(all(seg[k]), x);
        if (z != seg[k].end()) {
            *z = y;
            sort(all(seg[k]));
        }
        k /= 2;
    }
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        seg[i + n].push_back(ar[i]);
    }
    build();
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b, c;
            cin >> a >> b >> c;
            cout << query(a - 1, b - 1, c) << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            update(ar[a - 1], b , a - 1);
            ar[a - 1] = b;
        }
    }
    return 0;
}
