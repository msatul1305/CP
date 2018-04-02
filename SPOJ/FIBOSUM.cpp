#include <bits/stdc++.h>
#define i64 long long

/*
 * 
 * Something wrong with this solution ? 
 * MAIN97 wasn't accepted using this style of exponentiation(struct)
 * NOT EVEN A TLE....
 */

const i64 mod = 1e9 + 7;

int t;
i64 n, m;

struct matrix {
	i64 a[2][2];
	matrix() {
		memset(a, 0, sizeof(i64)*4);
	}
	matrix(int i) {
		memset(a, 0, sizeof(i64)*4);
		if(i == 1) {
			a[0][0] = a[1][1] = i;
		} else {
			a[0][0] = 0;
			a[0][1] = a[1][1] = a[1][0] = 1;
		}
	}
	matrix operator*(matrix b) {
		matrix c;
		for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
		for(int k = 0; k < 2; k++) {
			i64 x = ((a[i][k]%mod) * (b.a[k][j]%mod)) % mod;
			c.a[i][j] = (c.a[i][j]%mod + x%mod) % mod;
		}
		return c;
	}
};

matrix matpow(matrix b, int x) {
	matrix res(1);
	while(x) {
		if(x&1) res = res * b;
		b = b*b;
		x /= 2;
	}
	return res;
}

i64 mulans(i64 a[1][2], i64 b[2][2]) {
	i64 ans[1][2] = {0};
	for(int i = 0; i < 1; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2; k++) {
				i64 x = ((a[i][k]%mod) * (b[k][j]%mod))%mod;
				ans[i][j] = (ans[i][j]%mod + x%mod)%mod;
			}
		}
	}
	return ans[0][0];
}

i64 solve(i64 x) {
	matrix b(2);
	b = matpow(b, x+2);
	i64 a[1][2] = {0, 1};
	i64 ans = mulans(a, b.a);
	return (ans - 1);
}


int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		printf("%lld\n", (solve(m)%mod - solve(n-1)%mod + mod)%mod);
	}
	return 0;
}
