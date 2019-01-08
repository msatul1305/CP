#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,int> pd;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<long long,long long> pl;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()
#define LB lower_bound
#define UB upper_bound

#define F0R(i,b) for (int i = 0; i < (b); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define R0F(i,b) for (int i = (b)-1; i >= 0; i--)
#define ROF(i,b) for (int i = (b); i >= a; i--)


double normaldis(pd a, pd b) {
    return max(a.F - b.F, a.S - b.S);
}

double dis(pd a, pd b) {
    double x = a.F - b.F;
    double y = a.S - b.S;
    return sqrt(x*x + y*y);
}

double pointline(pd a, pd b, pd x) {
    sqrt(dis(a, b) - normaldis(b, x));
}

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    cout << fixed << setprecision(9);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pd> in(n);
        F0R(i,n)
            cin >> in[i].F >> in[i].S;
        int m;
        cin >> m;
        vector<pd> out(m);
        F0R(i,m)
            cin >> out[i].F >> out[i].S;
        double ans = 1000000000;
        //in points out segments
        F0R(i,n) F0R(j,m) {
            ans = min(ans, pointline(out[j], out[(j+1) % m], in[i]));
        }
        //in segments out points
        F0R(i,m) F0R(j,n) {
            ans = min(ans, pointline(in[j], in[(j+1) % n], out[i]));
        }
        cout << ans << '\n';
    }
    return 0;
}
