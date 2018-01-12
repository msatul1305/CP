#include <bits/stdc++.h>
using namespace std;

int t;
char ch;
string s;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &t);
	ch = getchar_unlocked();
	while(t--) {
		cin >> s;
		long long sz = s.size();
		long long ans = 0 - 48*sz;
		ans = accumulate(begin(s), end(s), ans);
		printf("%lld\n", ans);
	}
	return 0;
}
