#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int a[N];
ll T[4*N], delta[4*N];

void build(int c, int tl, int tr) {
    if (tl == tr) {
        T[c] = T[tl];
        return;
    }
    
    int tm = (tl + tr) / 2;
    
    build(2*c, tl, tm);
    build(2*c + 1, tm+1, tr);
    
    T[c] = T[2*c] + T[2*c + 1];
}

void refresh(int c){
    T[c] = T[2*c] + T[2*c + 1];
}

void propagate(int c, int tl, int tr) {
    T[c] += (tr - tl + 1) * delta[c];
    if (tr != tl) {
        delta[2*c] += delta[c];
        delta[2*c + 1] += delta[c];
    }
    delta[c] = 0;
}

void update(int c, int tl, int tr, int ul, int ur, int val) {
    
    if (delta[c])
        propagate(c, tl, tr);
    
    if (ur < tl || tr < ul)
        return;
    
    if (ul <= tl && tr <= ur) {
        delta[c] += val;
        propagate(c, tl, tr);
        return;
    }
    
    int tm = (tl + tr) / 2;
    
    update(2*c, tl, tm, ul, ur, val);
    update(2*c + 1, tm + 1, tr, ul, ur, val);
    
    refresh(c);
}

ll query(int c, int tl, int tr, int ql, int qr) {
    if (qr < tl || tr < ql)
        return 0;
    if (delta[c] != 0)
        propagate(c, tl, tr);
    if (ql <= tl && tr <= qr) {
        return T[c];
    }
    
    int tm = (tl + tr) / 2;
    
    ll r = query(2*c, tl, tm, ql, qr);
    r += query(2*c + 1, tm + 1, tr, ql, qr);
    
    return r;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c;
        scanf("%d %d", &n, &c);
        while (c--) {
            int q, a, b, v;
            scanf("%d", &q);
            if (q == 0) {
                scanf("%d %d %d", &a, &b, &v);
                update(1, 0, n-1, a-1, b-1, v);
            } else {
                scanf("%d %d", &a, &b);
                printf("%lld\n", query(1, 0, n-1, a-1, b-1));
            }
        }
        if (t) {
            memset(delta, 0, sizeof(delta));
            memset(T, 0, sizeof(T));
        }
    }
    return 0;
}
