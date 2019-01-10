#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		string a;
		for (char i = 'a'; i <= 'z'; i++) a.push_back(i);
		for (int i = 0; i < n; i++) {
			cout << a[i%k];
		}
		cout << '\n';
	}
	return 0;
}
