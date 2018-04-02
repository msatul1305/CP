//O(n^2)
#include <bits/stdc++.h>
using namespace std;
#define Long long long
#define sz(x) (int)(x).size()

const int maxn = 1e4 + 5;

int n, ans;
int len[maxn], ar[maxn];

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", ar + i);
	}
	for(int i = 0; i < n; i++) {
		int best = 0;
		len[i] = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(ar[i] > ar[j])
				best = max(best, len[j]);
		}
		len[i] += best;
		ans = max(ans, len[i]);
	}
	/* BOOK
	for(int i = 0; i < n; i++) {
		len[i] = 1;
		for(int j = i; j < i; j++) {
			if(ar[j] < ar[i])
				len[i] = max(len[j], len[i] + 1)
		}
		ans = max(len[i], ans);
	}
	*/
	printf("%d\n", ans);
	return 0;
}
