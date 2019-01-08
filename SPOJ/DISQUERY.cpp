#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 5;

int t;
int n, sz;

vector<int> G[N];
int ft[N], ht[N];
vector<int> tour, st;

void euler(int u, int p, int d) {
    ft[u] = tour.size();
    ht[u] = d;
    tour.push_back(u);
    for (int v : G[u]) {
        if (v == p) continue;
        euler(v, u, d + 1);
        tour.push_back(u);
    }
}

void build() {
    sz = tour.size();
    st.resize(3 * sz);
    for (int i = 0; i < sz; i++) st[i + sz] = tour[i];
    for (int i = sz-1; i >= 1; i--) {
        int tl = 2*i, tr = tl + 1;
        st[i] = ht[st[tl]] < ht[st[tr]] ? st[tl] : st[tr];
    }
}

int query(int l, int r) {
    l = ft[l] + sz, r = ft[r] + sz;
    if (r < l) swap(l, r);
    int ans = 0;
    while (l <= r) {
        if (l%2 == 1) {
            ans = ht[ans] < ht[st[l]] ? ans : st[l];
            l++;
        }
        if (r%2 == 0) {
            ans = ht[ans] < ht[st[r]] ? ans : st[r];
            r--;
        }
        l /= 2, r /= 2;
    }
    return ans;
}

void lca(int rt) {
    ht[0] = inf;
    euler(rt, -1, 1);
    build();
}

int m, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    return 0;
}
