#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 1;
int par[N];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

void merge(int a, int b) {
    par[get(a)] = get(b);
}

int n, q, a, b;
char type;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i <= n; i++) par[i] = i;
    for (int i = 0; i < q; i++) {
        scanf(" %c %d %d", &type, &a, &b);
        if (type == '?') {
            if (get(a) == get(b)) puts("yes");
            else puts("no");
        } else {
            merge(a, b);
        }
    }
    return 0;
}
