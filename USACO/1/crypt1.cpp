/*
ID: <hidden>
PROG: crypt1
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int n, ans;
set<int> T;

int digit(int x) {
	while(x) {
		if(T.find(x % 10) == T.end())
			return 0;
		x /= 10;
	}
	return 1;
}


int Dvalid(int x) {
	int sz = 0;
	while(x) {
		sz++;
		if(T.find(x % 10) == T.end())
			return 0;
		x /= 10;
	}
	if(sz == 3)
		return 1;
	else
		return 0;
}

int Pvalid(int x) {
	int sz = 0;
	while(x) {
		sz++;
		if(T.find(x % 10) == T.end())
			return 0;
		x /= 10;
	}
	if(sz == 4)
		return 1;
	else
		return 0;
}

int main() {
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1) {
		int t; scanf("%d", &t);
		T.insert(t);
	}
	for(int a = 11; a <= 99; a += 1) if(digit(a)) {
		for(int b = 111; b <= 999; b += 1) if(digit(b)) {
			if(Pvalid(a * b) && Dvalid((a % 10) * b) && Dvalid((a / 10) * b)) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
