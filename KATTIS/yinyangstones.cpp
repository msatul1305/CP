#include <bits/stdc++.h>
using namespace std;

string s;
int b, w;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	cin >> s;
	for(int i = 0; i < (int)s.size(); i += 1) {
		if(s[i] == 'W') w++;
		if(s[i] == 'B') b++;
	}
	if(w == b)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
