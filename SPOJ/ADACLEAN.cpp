#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(x) (int)x.size()

const int MAX = 1e5 + 5;
const int p = 53;
const int m = 1e9 + 7;

vector<ll> pi(MAX);

void precomp() {
	pi[0] = 1;
	for (int i = 1; i < MAX; i++) {
		pi[i] = (pi[i - 1] * p) % m;
	}
}

int t;
int n, k;

int main() {
	precomp();
	cin >> t;
	while (t--) {
		set<ll> st;
		string s;
		cin >> n >> k;
		cin >> s;
		
		vector<ll> h(n + 2);
		h[0] = 0;
		for (int i = 0; i < n; i++)
			h[i + 1] = (h[i] + pi[i] * (s[i] - 'a' + 1)) % m;
		
		for (int i = 0; i <= n - k; i++) {
			ll cur = ((h[i + k] + m - h[i]) * pi[n - i - 1]) % m;
			st.insert(cur);
		}
		cout << st.size() << '\n';
	}
	return 0;
}

