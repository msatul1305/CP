#include <bits/stdc++.h>
using namespace std;

int a[105];
int i = -1;
int n, ns = -1;
int ans;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	string x;	
	while(getline(cin, x)) {
		a[++i] = x.size();
		ns = max(ns, a[i]);
	}
	for(int j = i - 1; j >= 0; j -= 1) {
		ans += pow(ns - a[j], 2);
	}
	cout << ans;
	return 0;
}
