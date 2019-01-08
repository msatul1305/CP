#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<long long> vl;
typedef pair<long long,long long> pl;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

#define F0R(i,b) for (int i = 0; i < (b); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define R0F(i,b) for (int i = (b)-1; i >= 0; i--)
#define ROF(i,b) for (int i = (b); i >= a; i--)

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    cout << fixed << setprecision(9);
    int tt;
    cin >> tt;
    while (tt--) {
        int c;
        cin >> c;
        vl es(c);
        F0R(t,c) {
            int n;
            cin >> n;
            F0R(i,n) {
                int x;
                cin >> x;
                es[t] += x;
            }
        }
        sort(all(es));
        double d = 0;
        FOR(i,1,c-1)
            es[i] += es[i-1];
        F0R(i,c)
            d += es[i];
        cout << d/c << '\n';
    }
    return 0;
}
