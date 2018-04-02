#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int sgs[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &sgs[i]);
	
	int h, t = 0, ans = 0;
	unordered_map<int, int> mp;
	for(h = 0; h < n; h++) {
		auto idx = mp.find(sgs[h]);
		if(idx != mp.end()) {
			ans = max(ans, h - t);
			for(; t <= idx->second; t++) {
				mp.erase(sgs[t]);
			}
			mp[sgs[h]] = h;
		} else {
			mp.insert({sgs[h], h});
		}
	}
	ans = max(ans, h - t);
	printf("%d\n", ans);
	return 0;
}
