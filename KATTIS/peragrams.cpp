#include <bits/stdc++.h>
using namespace std;

string s;
int hm[123];

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	cin >> s;
	for(int i = 0; i < s.size(); i += 1) {
		hm[s[i]]++;
	}
	int odd = 0;
	for(int i = 97; i <= 122; i += 1) {
		if(hm[i]&1) odd++;
	}
	if(odd == 0 || odd == 1)
		cout << 0;
	else 
		cout << odd - 1;
	return 0;
}
