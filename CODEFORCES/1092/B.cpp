#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < n; i += 2) {
		ans += abs(a[i] - a[i+1]);
	}
	cout << ans << '\n';
	return 0;
}
