#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

const int mod = 1e9 + 7;

int t;
Int n;

void mul(Int x[][2], Int y[][2]) {	
	Int c[2][2] = {0};
	for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	for(int k = 0; k < 2; k++)
		c[i][j] = (c[i][j] % mod + ((x[i][k]%mod) * (y[k][j]%mod)) % mod) % mod;
	for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
		x[i][j] = c[i][j];
}

Int powm(Int b[][2], Int a) {
	Int c[2][2] = {0};
	c[0][0] = c[1][1] = 1;
	while(a) {
		if(a&1) mul(c, b);
		mul(b, b);
		a >>= 1;
	}
	return c[1][0];
}

Int solve() {
	Int mat[][2] = {{0, 1}, {1, 1}};
	Int ans = powm(mat, n+3);
	return ans;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		if(n == 0) printf("0\n");
		else if(n == 1) printf("2\n");
		else printf("%lld\n", solve());
	}
	return 0;
}
