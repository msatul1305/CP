#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int up = 0, down = 0, as = 0;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == 'D') up++;
		if (s[i] == 'U') down++;
		if (s[i] != s[i-1]) as++;
	}
	up *= 2;
	down *= 2;
	if (s[0] == 'D' && s[1] == 'D') up--;
	if (s[0] == 'D' && s[1] == 'U') up++;
	if (s[0] == 'U' && s[1] == 'U') down--;
	if (s[0] == 'U' && s[1] == 'D') down++;
	cout << up << '\n';
	cout << down << '\n';
	cout << as << '\n';
	return 0;
}
