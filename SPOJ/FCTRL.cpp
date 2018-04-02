#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		ll r = 0,x = 5;
		while(n/x > 0) {
			r += n/x;
			x *= 5;
		}
		cout << r << '\n';
	}
	return 0;
} 