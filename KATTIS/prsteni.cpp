#include <bits/stdc++.h>
using namespace std;

int __lcm(int a, int b) {
	return (a * b)/__gcd(a, b);
}

int n, a, t;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	scanf("%d", &n);
	scanf("%d", &a);
	for(int i = 1; i < n; i += 1) {
		scanf("%d", &t);
		int lcm = __lcm(a, t);
		printf("%d/%d\n", lcm/t, lcm/a);
	}
	return 0;
}
