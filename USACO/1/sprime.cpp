/*
ID: lunu1991
TASK: sprime
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isprime(int x) {
    if (x % 2 == 0 && x != 2) return false;
    for (int i = 3; 1LL*i*i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

vector<int> can;
int n;

void gen(int num, int lim) {
    if (lim == n) {
        can.push_back(num);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (i != 1 && i != 4 && i != 6 && i != 8 || (i == 1 && lim != 0)) {
            int cur = num*10 + i;
            if (isprime(cur))
                gen(cur, lim + 1);
        }
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    scanf("%d", &n);
    gen(0, 0);
    for (int i = 0; i < can.size(); i++) {
        printf("%d\n", can[i]);
    }
    return 0;
}

