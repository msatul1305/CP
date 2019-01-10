#include <bits/stdc++.h>
using namespace std;

bool prefix(string big, string smal) {
	int ss = smal.size(), bs = big.size();
	for (int i = 0; i < smal.size(); i++) {
		if (smal[i] != big[i])
			return false;
	}
	return true;
}

bool suffix(string big, string smal) {
	int ss = smal.size(), bs = big.size();
	for (int i = 0; i < smal.size(); i++) {
		if (smal[ss - 1 - i] != big[bs - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int sz = n;
	n = 2*n - 2;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<int> sol;//0 prefix ; 1 suffix
	for (int i = 0; i < n; i++) {
		if (s[i].size() == sz-1) {
			for (int j = 0; j < n; j++) {
				if (i != j && s[j].size() == 1) {
					string ps = s[j] + s[i];
					vector<int> z(n);
					int chk = 0;
					set<int> zs;
					for (int  i = 0; i < n; i++) {
						if (suffix(ps, s[i]) && zs.find((int)s[i].size()) == zs.end()) {
							z[i] = 1;
							zs.insert((int)s[i].size());
						} else {
							z[i] = 0;
						}
						chk += z[i];
					}
					if (chk == n/2) {
						int chk2 = 0;
						for (int i = 0; i < n; i++) {
							if(z[i] == 0) {
								if (prefix(ps, s[i])) {
									chk2++;
								}
							}
						}
						if (chk2 == chk) {
							sol = z;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (sol[i] == 0) {
			cout << "P";
		} else {
			cout << "S";
		}
	}
	cout << '\n';
	return 0;
}
