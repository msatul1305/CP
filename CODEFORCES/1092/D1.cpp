#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= 2;
	}
	stack<int> s;
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(a[i]);
		} else {
			if (s.top() == a[i]) {
				s.pop();
			} else {
				s.push(a[i]);
			}
		}
	}
	if (s.size() > 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
	return 0;
}
