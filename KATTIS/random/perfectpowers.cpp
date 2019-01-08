#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int main() {
    while(scanf("%d", &n) && n) {
        map<int, int> roots;
        bool neg = n < 0;
        n = neg ? -n : n;
        while (n % 2 == 0) roots[2] += 1, n /= 2;
        for (int p = 3; 1*LL*p*p <= n; p += 2) {
            cout << p*p << '\n';
            while (n % p == 0) {
                roots[p]++;
                n /= p;
            }
        }
        if (n > 1) roots[n]++;
        int ans;
        for (ans = 32; ans >= 1; ans--) {
            bool all = true;
            for (auto x : roots) {
                if (x.second % ans != 0) {
                    all = false;
                    break;
                }
            }
            if(all == true && (!neg || (neg && ans&1))) break;
            
        }
        printf("%d\n", ans);
    }
    return 0;
}
