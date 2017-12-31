#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

struct v {
	int vd;
	long long w;
};

vector< vector<v> > g(maxn);
long long ans[maxn];
bool used[maxn];
int ians;

void dfs(int x, long long d) {
	ans[ians] = max(ans[ians], d);
	used[x] = true;
	for(auto i = g[x].begin(); i != g[x].end(); i++) {
		if(!used[i->vd])
			dfs(i->vd, d + i->w);
	}
}

int main() {
	freopen("EAGLE1.in", "r", stdin);
	int t; scanf("%d", &t);
	while(t--) {
		ians = 0;
		int n; scanf("%d", &n);
		for(int j = 1; j < n; j++) {
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			g[x].push_back({y, z});
			g[y].push_back({x, z});
		}

		for(int j = 1; j <= n; j++) {
			dfs(j, 0L);
			memset(used, 0, sizeof(used));
			ians++;
		}
		for(int j = 0; j < ians; j++) {
			printf("%lld%c", ans[j], " \n"[j == ians-1]);
		}
	}
	return 0;
}
