#include <iostream>
#include <string>
using namespace std;

string s;

int igr(int c) {
	return c-96;
}

bool valid(char c) {
	return (c >= 1 && c <=26);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	while(1) {
		cin >> s;
		if(s == "0") break;
		s += 'z';
		long long ans = 1;
		for(int i = 1; i < (int)s.size(); i++) {
			if(valid(s[i])) ans++;
			if(valid(igr(s[i] + s[i + 1]))) ans += 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
