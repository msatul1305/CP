#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

string s, ans;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	cin >> s;
	stack<char> S;
	for(int i = 0; i < sz(s); i++) {
		if(s[i] != '<') S.push(s[i]);
		else S.pop();
	}
	for(;!S.empty(); S.pop()) {
		ans.push_back(S.top());
	}
	reverse(begin(ans), end(ans));
	cout << ans;
	return 0;
}
