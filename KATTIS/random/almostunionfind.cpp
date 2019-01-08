#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int par[N], sz[N], sum[N];

void build(int n) {
    for (int i = 1, j = n + 1; i <= n; i++, j++) {
        par[i] = j;
        sz[j] = 1;
        sum[j] = i;
        par[j] = j;
    }
}

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

void move(int x, int to) {
    int Px = get(x);
    int Pto = get(to);
    if (Px == Pto) return;
    sz[Px] -= 1;
    sum[Px] -= x;
    par[x] = Pto;
    sz[Pto] += 1;
    sum[Pto] += x;
}

void merge(int fr, int to) {
    int Pfr = get(fr);
    int Pto = get(to);
    if (Pfr != Pto) {
        par[Pfr] = Pto;
        sz[Pto] += sz[Pfr];
        sum[Pto] += sum[Pfr];
    }
}

int n, m;
int o, p, q;

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        build(n);
        while (m--) {
            scanf("%d", &o);
            if (o == 1) {
                scanf("%d %d", &p, &q);
                merge(p, q);
            } else if (o == 2) {
                scanf("%d %d", &p, &q);
                move(p, q);
            } else {
                scanf("%d" ,&p);
                q = get(p);
                printf("%d %d\n", sz[q], sum[q]);
            }
        }
    }
    return 0;
}
