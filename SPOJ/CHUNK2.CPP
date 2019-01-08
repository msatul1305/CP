#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100005;
const int M = 1299709;

int read() {
    bool neg = false;
    int x = 0; char ch = getchar_unlocked();
    while(ch < '0' || ch > '9') { if(ch == '-') neg = true; ch = getchar_unlocked(); }
    while(ch >= '0' && ch <= '9') { x = x*10+ch-48; ch = getchar_unlocked(); }
    if(neg) return -x;
    return x;
}

void write(int x) {
    if(x < 0) { x = -x; putchar_unlocked('-'); }
    if(x > 9) write(x/10);
    putchar_unlocked(x%10+48);
}

int par[N], sze[N];

bitset<M> c;
int primes[N];

void sieve() {
    int m = sqrt(M) + 1, idx = 1;
    primes[idx++] = -1;
    for (int i = 4; i <= M; i += 2) c[i] = 1;
    for (int i = 3; i <= M; i += 2) if (!c[i]) {
        primes[idx++] = i;
        for (int j = i+i; j <= M; j += i)
            c[j] = 1;
    }
}

int get(int x) {
    if (par[x] != x)
        par[x] = get(par[x]);
    return par[x];
}

void init() {
    for (int i = 1; i < N; i++) {
        par[i] = i;
        sze[i] = 1;
    }
}

void unite(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return;
    if (sze[a] < sze[b]) swap(a, b);
    sze[a] += sze[b];
    par[b] = a;
}

int main() {
    sieve();
    int t = read();
    while (t--) {
        init();
        int n = read(), m = read();
        int k = 1;
        for (int i = 0; i < m; i++) {
            int u = read(), v = read();
            unite(u, v);
            k = max(k, sze[get(u)]);
        }
        write(primes[k]);
        putchar_unlocked('\n');
    }
    return 0;
}
