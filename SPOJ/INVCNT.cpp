#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int ar[N];
int n, t;

ll getINV(int l, int mid, int r) {
    ll cur = 0;
    int *tmp = new int[r - l + 5];
    int i = l, j = mid + 1, k = 0;
    
    while (i <= mid && j <= r) {
        if (ar[i] <= ar[j]) {
            tmp[k++] = ar[i++];
        } else {
            cur += mid + 1 - i;
            tmp[k++] = ar[j++];
        }
    }
    while (i <= mid) tmp[k++] = ar[i++];
    while (j <= r) tmp[k++] = ar[j++];
    k = 0;
    while (l <= r) ar[l++] = tmp[k++];

    delete []tmp;
    return cur;
}

ll findINV(int l, int r) {
    int mid; ll cur = 0;
    if (l < r) {
        mid = (l + r) / 2;
        cur = findINV(l, mid);
        cur += findINV(mid + 1, r);
        cur += getINV(l, mid, r);
    }
    return cur;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
        ll ans = findINV(0, n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
