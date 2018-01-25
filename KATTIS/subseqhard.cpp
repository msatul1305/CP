#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define Long long long

int t, n;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		Long E = 0, tm, ans = 0;
		unordered_map<Long, Long> mp;
		mp.insert({0, 1});
		for(int i = 0; i < n; i++) {
			scanf("%lld", &tm);
			E += tm;
			auto f = mp.find(E);
			if(f == mp.end()) {
				mp.insert({E, 1});
			} else {
				f->second += 1;//how many previous prefix sums are equal to E-47
			}
			if((f = mp.find(E - 47)) != mp.end()) {
				ans += f->second;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
