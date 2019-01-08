#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 1;

int n, m;
int a[N];
int t[4*N];

void build(int c = 1, int tl = 0, int tr = n-1) {
    if (tl == tr) {
        t[c] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2*c, tl, tm);
    build(2*c + 1, tm+1, tr);
    t[c] = max(t[2*c], t[2*c + 1]);
}

int q;
int ans;

void query(int c = 1, int tl = 0, int tr = n-1) {
    if (tl == tr) {
        ans = tl + 1;
        t[c] -= q;
        return;
    }
    int tm = (tl + tr) / 2;
    if (t[2*c] >= q)
        query(2*c, tl, tm);
    else
        query(2*c + 1, tm+1, tr);
    t[c] = max(t[2*c], t[2*c + 1]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build();
    for (int i = 0; i < m; i++) {
        cin >> q;
        if (t[1] >= q) {
            query();
            cout << ans << ' ';
        } else {
            cout << "0 ";
        }
    }
    cout << '\n';
    return 0;
}
