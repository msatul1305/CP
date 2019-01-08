#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> dp;

ll f(ll n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (dp[n]) return dp[n];
	ll b = 0;
	while ((1LL<<b) <= n) b++;
	b = (1LL<<(b-1)) - 1;
	dp[n] = f(n - b - 1) + (n-b) + f(b);
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	cout << f(n) << '\n';
    return 0;
}

