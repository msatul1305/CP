#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1e5+10;
int trib[maxn];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> trib[0] >> trib[1] >> trib[2];
	int n; cin >> n;
	for(int i = 3; i <= n; i++) {
		trib[i] = trib[i-1] + trib[i-2] - trib[i-3];
	}
	cout << trib[n] << "\n";
	return 0;
}