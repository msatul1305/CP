#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<ll, ll> pl;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define LB lower_bound
#define UB upper_bound
#define all(x) (x).begin(), (x).end()

#define F0R(i,b) for (int i = 0; i < (b); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define rF0R(i,b) for (int i = (b)-1; i >= 0; i--)
#define rFOR(i,b) for (int i = (b); i >= a; i--)

double l, w, r;
pd pt[4];
vector<pd> cr;
int chk[4];
int n, ans;

double dis(pd a, pd b) {
    return hypot(a.F - b.F, a.S - b.S);
}

int ok() {
    return ((chk[0]>0)+(chk[1]>0)+(chk[2]>0)+(chk[3]>0)) == 4;
}

void f(pd &c, int x) {
    for (int p = 0; p < 4; p++) {
        if (dis(pt[p], c) <= r)
            chk[p] += x;
    }
}

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    cout << fixed << setprecision(9);
    
    cin >> l >> w >> n >> r;
    pt[0] = {-l/2, 0};
    pt[1] = {l/2, 0};
    pt[2] = {0, -w/2};
    pt[3] = {0, w/2};
    
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        for (int p = 0; p < 4; p++) {
            if (dis(pt[p], {a, b}) <= r) {
                cr.PB({a,b});
                break;
            }
        }
    }
    n = cr.size();
    ans = n+5;
    for (int i = 0; i < n; i++) {
        f(cr[i], 1);
        if (ok()) ans = min(ans, 1);
        for (int j = i+1; j < n; j++) {
            f(cr[j], 1);
            if (ok()) ans = min(ans, 2);
            for (int k = j+1; k < n; k++) {
                f(cr[k], 1);
                if (ok()) ans = min(ans, 3);
                for (int l = k+1; l < n; l++) {
                    f(cr[l], 1);
                    if (ok()) ans = min(ans, 4);
                    f(cr[l], -1);
                }
                f(cr[k], -1);
            }
            f(cr[j], -1);
        }
        f(cr[i], -1);
    }
    if (ans == n+5)
        cout << "Impossible\n";
    else
        cout << ans << '\n';
    return 0;
}
