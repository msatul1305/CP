/*
ID: <hidden>
TASK: dualpal
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

bool pal(string x) {
	string t(x);
	reverse(begin(x), end(x));
	return (x == t);
}

int fetch(int m) {
	int ans = 0;
	for(int B = 2; B <= 10; B++) {
		int n = m;
		string x = "";
		while(n) {
			int t = n % B;
			x.push_back(t + 48);
			n /= B;
		}
		if(pal(x)) ans++;
	}
	return ans;
}

int main() {
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n, s; cin >> n >> s;
	while(n) {
		if(fetch(++s) >= 2) {
			cout << s << '\n';
			n--;
		}
	}
	return 0;
}
