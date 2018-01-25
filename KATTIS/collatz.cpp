#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
#define Long long long
#define ump unordered_map<Long, Long>

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	while(1) {
		Long n[2], c, nc , s[2] = {0};
		scanf("%lld %lld", &n[0], &n[1]);
		if(n[0] == 0) break;
		ump map;
		Long go = n[0], qu = n[1];
		map.insert({go, s[0]});
		while(go != 1) {
			if(go&1) go = go * 3 + 1;
			else go /= 2;
			map.insert({go, ++s[0]});
		}
		ump::iterator ans = map.find(qu);
		while(ans == map.end()) {
			if(qu&1) qu = qu * 3 + 1;
			else qu /= 2;
			++s[1];
			ans = map.find(qu);
		}
		printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", n[0], ans->second, n[1], s[1], ans->first);
	}
	return 0;
}
