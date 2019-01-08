#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100005;

int s[N];

int t, n, c;

bool chk(int x) {
    ll last = s[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (last + x <= s[i]) {
            cnt++;
            last = s[i];
        }
    }
    if (cnt >= c) {
        return true;
    } else {
        return false;
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &c);
        for (int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        sort(s, s + n);
        int l = 0, h = 1e9;
        while (l <= h) {
            int m = (l + h) / 2;
            int cp = chk(m);
            if (cp == true && chk(m + 1) == false) {
                printf("%d\n", m);
                break;
            } else {
                if (cp == false)
                    h = m - 1;
                else
                    l = m + 1;
            }
        }
    }
    return 0;
}
