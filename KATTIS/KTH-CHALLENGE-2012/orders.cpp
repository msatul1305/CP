#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[105], k[1005];
int amb[30005], lst[30005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	int mxk = 0;
	for (int i = 0; i < m; i++)
		cin >> k[i], mxk = max(mxk, k[i]);
	for (int i = 0; i <= mxk; i++) lst[i] = -1;
	lst[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= mxk; j++) {
			if (lst[j] >= 0) {
				if (lst[j + a[i]] == -1)
					lst[j + a[i]] = i;
				else
					lst[j + a[i]] = -10;
			}
			if (lst[j] == -10)
				lst[j + a[i]] = -10;
		}
	}
	for (int i = 0; i < m; i++) {
		int x = k[i];
		if (lst[x] == -1) {
			cout << "Impossible\n";
		} else if (lst[x] == -10) {
			cout << "Ambiguous\n";
		} else {
			vector<int> ans;
			while (x > 0) {
				ans.push_back(lst[x] + 1);
				x -= a[lst[x]];
			}
			sort(ans.begin(), ans.end());
			for (int z : ans)
				cout << z << ' ';
			cout << '\n';
		}
	}
	return 0;
}
