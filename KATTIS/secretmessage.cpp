#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int t, a = 1;
string s;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	cin >> t;
	while(t--) {
		cin >> s;
		a = ceil(sqrt(sz(s)));
		vector< vector<char> > M(a, vector<char> (a, '*'));
		int it = 0;
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < a; j++) {
				if(it == sz(s)) {
					i = a;
					break;
				}
				M[i][j] = s[it++];
			}
		}
		for(int i = 0; i < a; i += 1) {
			for(int j = a - 1; j >= 0; j -= 1) if(M[j][i] != '*') {
				printf("%c", M[j][i]);
			}
		}
		puts("");
	}
	return 0;
}
