/*
ID: <hidden>
TASK: combo
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int N, ans;

int f1, f2, f3;
int m1, m2, m3;

bool two(int x, int y) {
	if(abs(x - y) <= 2 || abs(x - y) >= N - 2)
		return true;
	return false;
}

bool chk(int a, int b, int c) {
	if(two(f1, a) && two(f2, b) && two(f3, c))
		return true;
	if(two(m1, a) && two(m2, b) && two(m3, c))
		return true;
	return false;
}

int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);

	scanf("%d", &N);
	scanf("%d %d %d", &f1, &f2, &f3);
	scanf("%d %d %d", &m1, &m2, &m3);
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			for(int k = 1; k <= N; k++) {
				if(chk(i, j, k)) ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
