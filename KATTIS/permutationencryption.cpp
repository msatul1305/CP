#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int n;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	while(1) {
		cin >> n;
		string str;
		if(n == 0) break;
		vector<int> V(n + 1);
		for(int i = 0; i < n; i++)
			cin >> V[i];
		char ch = getchar();
		getline(cin, str);
		if(n == 1) {
			cout << "'";
			cout << str;
			cout << "'" << '\n';
			continue;
		}
		int p = 0;
		if(sz(str) % n) {
			p = n - sz(str) % n;
		}
		int lim = p + sz(str);
		for(int i = 0; i < p; i++)
			str.push_back(' ');
		cout << "'";
		for(int i = 0; i < lim; i += n) {
			for(int j = 0; j < n; j++) {
				cout << str[i + V[j] - 1];
			}
		}
		cout << "'";
		cout << '\n';
	}
	
	return 0;
}
