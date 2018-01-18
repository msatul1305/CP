#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

long long ar[maxn];

void precompute() {
	for(int i = 1; i < maxn; i++)
		for(int j = 2*i; j < maxn; j += i)
			ar[j] += i;
}

int t, q;

int main() {
	//freopen("in.txt", "r", stdin);
	precompute();
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &q);
		printf("%lld\n", ar[q]);
	}
	return 0;
}
