#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll b[20005];

int main() {
	ll l, d, n;
	ll ans = 0;
	cin >> l >> d >> n;
	b[0] = 6 - d;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	b[n+1] = l - 6 + d;
	sort(b, b + n + 2);
	for (int i = 1 ; i <= n+1; i++)
		ans += ((b[i] - b[i-1]) / d) - 1;
	cout << ans << '\n';
	return 0;
}
