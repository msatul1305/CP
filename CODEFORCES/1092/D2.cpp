#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = -1, f = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(a[i], mx);
	}
	stack<int> s;
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(a[i]);
		} else {
			if (s.top() == a[i]) {
				s.pop();
			} else if (s.top() > a[i]) {
				s.push(a[i]);
			} else {
				f = 0;
				break;
			}
		}
	}
	if (f == 1 && s.size() == 1 && s.top() == mx || s.empty()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
