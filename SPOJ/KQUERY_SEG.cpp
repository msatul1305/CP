#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e4 + 5;
const int M = 2e5 + 5;

struct D {
    int num, idx;
    bool operator < (const D &b) {
        return num > b.num;
    }
} A[N];

struct Q {
    int l, r, idx, val;
    bool operator < (const Q &b) {
        return val > b.val;
    }
} B[M];

int tree[N<<1], ans[M];

int n, q;

void add(int k) {
    k += n;
    tree[k] = 1;
    for (k /= 2; k > 0 ; k /= 2)
        tree[k] = tree[2*k] + tree[2*k + 1];
}

int get(int l, int r) {
    int s = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l%2 == 1) s += tree[l++];
        if (r%2 == 0) s += tree[r--];        
    }
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i].num);
        A[i].idx = i;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &B[i].l, &B[i].r, &B[i].val);
        B[i].idx = i;
    }
    sort(A + 1, A + n + 1);
    sort(B, B + q);
    for (int i = 0, cur = 1; i < q; i++) {
        while (A[cur].num > B[i].val)
            add(A[cur++].idx);
        ans[B[i].idx] = get(B[i].l, B[i].r);
    }
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}
