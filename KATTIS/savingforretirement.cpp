#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int p, q, r;
int x, y;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	cin >> a >> b >> c >> p >> q;
	x = (b - a) * c;
	int i;
	for(i = 1; x >= y; i += 1) {
		y = i * q;
	}
	cout << --i + p;
	return 0;
}
