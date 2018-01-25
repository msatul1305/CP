#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()


int n;

//custom hash function
int doit(string &s) {
	int xr = s[0];
	for(int i = 1; i < sz(s); i++)
		xr ^= s[i];
	return xr;
}

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	while(cin >> n && n != 0) {
		cin.ignore();
		unordered_set<string> U;
		vector<string> V;
		int c = 0;
		while(n--) {
			string s; getline(cin, s);
			U.insert(s); V.push_back(s);			
		}
		for(int i = sz(V) - 1; i >= 1; i--) {
			int hc = doit(V[i]);
			for(int j = i - 1; j >= 0; j--) {
				if(hc == doit(V[j]) && V[i] != V[j]) c++;
			}
		}
		cout << sz(U) << ' ' << c << '\n';
	}
	return 0;
}
