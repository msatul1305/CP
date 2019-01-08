/*
ID: lunu1991
PROG: sort3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

int A[N];
int n;

int get(int l, int mid, int r) {
    int aux[r - l + 5] = {0};
    int cnt = 0;
    int i = l, j = mid + 1, a = 0;
    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) {
            aux[a++] = A[i++];
        } else {
            cnt += mid + 1 - i;
            aux[a++] = A[j++];
        }
    }
    while (i <= mid) aux[a++] = A[i++];
    while (j <= r) aux[a++] = A[j++];
    a = 0;
    while (l <= r) A[l++] = aux[a++];
    return cnt;
}

int find(int l, int r) {
    int cnt = 0;
    if (l < r) {
        int mid = (l + r) / 2;
        cnt += find(l, mid);
        cnt += find(mid + 1, r);
        cnt += get(l, mid, r);
    }
    return cnt;
}

int main() {
    freopen("in.txt", "r", stdin);
    //freopen("sort3.in", "r", stdin);
    //freopen("sort3.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d\n", &A[i]);
    int ans = find(0, n - 1);
    printf("%d\n", ans);
    
}
