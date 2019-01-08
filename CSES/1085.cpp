#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;

ll a[N];
int n, k;

bool chk(ll s) {
    ll csm = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        csm += a[i];
        if(csm > s) {
            csm = a[i];
            cnt++;
        }
    }
    if (cnt >= k)
        return true;
    return false;
}

int main() {
    cin >> n >> k;
    
    ll l = 0, r = 0, m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(a[i], l);
        r += a[i];
    }
    
    while (l <= r) {
        
        m = l + (r - l) / 2;
        
        if (chk(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << l << '\n';
    
    return 0;
}
