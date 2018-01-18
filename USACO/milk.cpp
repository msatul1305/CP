/*
ID: <HIDDEN>
TASK: milk
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vii vector<pi> 

bool ed(const pi &a, const pi &b) {return (a.first < b.first);}; 

int main() {
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	int n, m, moneh = 0; scanf("%d%d", &n, &m);
	if(n != 0 && m != 0) {
		vii V;
		for(int i = 0; i < m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			V.push_back({x, y});
		}
		sort(V.begin(), V.end(), ed);
		int milk = 0, i;
		for(i = 0; i < V.size(); i++) {
			if(V[i].second < (n-milk)) {
				moneh += V[i].first * V[i].second;
				milk += V[i].second;
			}
			else 
				break;
		}
		moneh += (n-milk) * V[i].first;
	}
	printf("%d\n", moneh);
	return 0;
}
