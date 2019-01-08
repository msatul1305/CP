/*
ID: lunu1991
PROG: pprime
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int l, r;
int nl, nr;

vector<int> C;
vector<int> ans;

int nod(int x) {
    int cnt = 0;
    for (int i = x; i != 0; i /= 10)
        ++cnt;
    return cnt;
}

int rev(int x) {
    int num = 0;
    for (int i = x; i != 0; i /= 10)
        num = num*10 + i%10;
    return num;
}

int piv;

void sendsingles() {
    for (int i = 1; i <= 9; i++)
        if (i >= l && i <= r)
            C.push_back(i);
}

void gen(int num, int lim, int cur) {
    if (lim == 0) return sendsingles();
    if (cur > lim) return;
    if (cur == lim) {
        int b;
        if (piv % 2 == 0) {
            b = num * pow(10, nod(num)) + rev(num);
            if (b >= l && b <= r)
                C.push_back(b);
        } else {
            for (int i = 0; i <= 9; i++) {
                int p = pow(10, nod(num) + 1);
                b = num * p + rev(num);
                b += p/10 * i;
                if (b >= l && b <= r)
                    C.push_back(b);
            }
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (num == 0 && i == 0) continue;
        gen(num * 10 + i, lim, cur + 1);
    }
}

bool isprime(int x) {
    if (x % 2 == 0 && x != 2) return false;
    for (int i = 3; 1LL*i*i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    scanf("%d %d", &l, &r);
    nl = nod(l), nr = nod(r);
    for (int i = nl; i <= nr; i++) {
        piv = i;
        gen(0, i / 2, 0);
        for (int i = 0; i < C.size(); i++) {
            if (isprime(C[i])) ans.push_back(C[i]);
        }
        C.clear();
    }
    sort(ans.begin(), ans.end());
    for (int x : ans)
        printf("%d\n", x);
    return 0;
}
