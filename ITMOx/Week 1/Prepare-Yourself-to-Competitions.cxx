#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define test(_) int _;cin >> _;while(_--)
#define V(_) vector<_>
#define P(_) pair<_>
#define scan(_) int _;cin >> _
#define print(_) cout << _
#define nd <<
#define newl '\n'

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scan(n);
	V(int) p, t, d;
	REP(i,1,n) {
		scan(temp);
		p.PB(temp);
	}
	REP(i,0,n-1) {
		scan(temp);
		t.PB(temp);
		d.PB(p[i] - t[i]);
	}
	int ans = 0;
	bool practice = false, theory = false;
	REP(i,0,n-1) {
		if(p[i] > t[i]) {
			practice = true;
			ans += p[i];
		}
		else {
			ans += t[i];
			theory = true;
		}
	}
	if(theory == false) {
		int minimal = 0;
		REP(i,1,n-1) {
			if(d[minimal] > d[i])
				minimal = i;
		}
		ans += t[minimal] - p[minimal];
	}
	if(practice == false) {
		int maximal = 0;
		REP(i,1,n-1) {
			if(d[maximal] < d[i])
				maximal = i;
		}
		ans += p[maximal] - t[maximal];
	}
	cout << ans << endl;
	return 0;
}
