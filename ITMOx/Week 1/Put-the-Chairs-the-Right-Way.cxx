#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	double a, b, c, ans;
	cin >> a >> b >> c;
	ans = (a+b+c)/6;
	printf("%.8f\n", ans);
	return 0;
}