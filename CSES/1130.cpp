#include <bits/stdc++.h>
using namespace std;

vector<int> G[500005];

int main () {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	return 0;
}
