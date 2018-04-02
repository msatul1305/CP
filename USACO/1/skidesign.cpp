/*
ID: <hidden>
TASK: skidesign
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int ans;

int main() {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	
	scanf("%d", &n);
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int mincost = INT_MAX;
	for(int s = 0; s <= 83; s++) {
		int e = s + 17;
		int cost = 0;
		for(int i = 0; i < n; i++) {
			if(h[i] > e) {
				cost += pow(h[i] - e, 2);
			} else if(h[i] < s) {
				cost += pow(s - h[i], 2);
			}
		}
		mincost = min(cost, mincost);
	}
	printf("%d\n", mincost);
	return 0;
}
