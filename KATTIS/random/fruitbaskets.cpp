#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	ll tot = (1LL<<(n-1)) * sum;
	for (int i = 0; i < n; i++) {
		if (a[i] < 200) tot -= a[i];
		for (int j = i+1; j < n; j++) {
			if (a[i] + a[j] < 200) tot -= a[i] + a[j];
			for (int k = j+1; k < n; k++) {
				if (a[i] + a[j] + a[k] < 200) tot -= a[i] + a[j] + a[k];
			}
		}
	}
	cout << tot << '\n';
	return 0;
}