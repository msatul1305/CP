#include <bits/stdc++.h>
using namespace std;

int n, p, q;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d%d", &n, &p, &q);
	int total = p + q + 1;
	int ans = total % (2*n);
	if(ans <= n && ans != 0)
		printf("paul\n");
	else
		printf("opponent\n");
	return 0;
}
