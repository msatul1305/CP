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

int bit[N], ans[M];

int n, q;

void add(int k) {
    for (int i = k; i <= n; i += i&-i)
        ++bit[i];
}

int get(int k) {
    int s = 0;
    for (int i = k; i >= 1; i -= i&-i)
        s += bit[i];
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
        ans[B[i].idx] = get(B[i].r) - get(B[i].l - 1);
    }
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}
