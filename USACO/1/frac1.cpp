/*
ID: lunu1991
TASK: frac1
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define F first
#define S second

struct cmp {
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
         return (double)lhs.F/lhs.S < (double)rhs.F/ rhs.S;
     }
};

int n;

pair<int, int> red(int x, int y) {
    int d = __gcd(x, y);
    return make_pair(x/d, y/d);

}

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    set< pair<int, int>, cmp > st;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            st.insert(red(j, i));
        }
    }
    puts("0/1");
    for (auto &x : st) {
        printf("%d/%d\n", x.F, x.S);
    }
    return 0;
}
