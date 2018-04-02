/*
ID: <hidden>
TASK: milk3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool vis[21][21][21];

int am, bm, cm;
vector<int> ans;

void solve(int a, int b, int c) {
	if(vis[a][b][c] == 1) return;

	vis[a][b][c] = 1;

	if(a == 0) ans.push_back(c);

	if(am - a != 0) {//c -> a
		int p = a + (c >= am - a ? am - a : c);
		int q = b;
		int r = c - (p - a);
		solve(p, q, r);
	}
	if(bm - b != 0) {//c -> b
		int p = a;
		int q = b + (c >= bm - b ? bm - b : c);
		int r = c - (q - b);
		solve(p, q, r);
	}
	if(am - a != 0) {//b -> a
		int p = a + (b >= am - a ? am - a : b);
		int q = b - (p - a);
		int r = c;
		solve(p, q, r);
	}
	if(cm - c != 0) {//b -> c
		int r = c + (b >= cm - c ? cm - c : b);
		
		int p = a;
		int q = b - (r - c);
		solve(p, q, r);
	}
	if(bm - b != 0) {//a -> b
		int q = b + (a >= bm - b ? bm - b : a);

		int p = a - (q - b);
		int r = c;
		solve(p, q, r);
	}
	if(cm - c != 0) {//a -> c
		int r = c + (a >= cm - c ? cm - c : a);

		int p = a - (r - c);
		int q = b;
		solve(p, q, r);
	}
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	scanf("%d %d %d", &am, &bm, &cm);

	solve(0, 0, cm);

	sort(ans.begin(), ans.end());

	for(int i = 0; i < (int)ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);

	return 0;
}
