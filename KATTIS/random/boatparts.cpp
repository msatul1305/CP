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

#define F0R(i,b) for (int i = 0; i < (b); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define rF0R(i,b) for (int i = (b)-1; i >= 0; i--)
#define rFOR(i,b) for (int i = (b); i >= a; i--)

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    cout << fixed << setprecision(9);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int tar, q;
        cin >> tar >> q;
        set<string> st;
        F0R(i,q) {
            string t;
            cin >> t;
            st.insert(t);
            if (st.size() == tar) {
                cout << i+1;
                exit(0);
            }
        }
        cout << "paradox avoided";
    }
    return 0;
}
