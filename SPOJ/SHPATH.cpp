#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 1;
const int INF = 0x3f3f3f3f;

struct graph {
	int to;
	int we;
	graph(){};
	graph(int x, int y): to(x), we(y) {};
};

int t;

class solve {
	private:
		int n, q;
		vector< graph > G[N];
		unordered_map< string, int > idx;
		string a, b;
	public:
		void init() {
			int ix = 1;
			cin >> n;
			for(int i = 0; i < n; i++, ix++) {
				cin >> a;
				idx.insert({a, ix});
				int con;
				cin >> con;
				for(int i = 0; i < con; i++) {
					int to, we;
					cin >> to >> we;
					G[ix].push_back({to, we});
				}
			}
			cin >> q;
			while(q--) {
				cin >> a >> b;
				cout << dji(idx[a], idx[b]) << '\n';
			}

		}
		ll dji(int so, int des) {
			bool vis[n + 1] = {0};
			ll dis[n + 1];

			memset(dis, INF, sizeof(dis));
			vis[so] = 1, dis[so] = 0;

			priority_queue< pair< ll, int > > Q;
			Q.push({0, so});

			while(!Q.empty()) {
				int f = Q.top().second; Q.pop();

				if(f == des) return dis[f];

				for(auto x : G[f]) {
					int t = x.to, w = x.we;
					if(dis[t] > dis[f] + w && !vis[t]) {
						dis[t] = dis[f] + w;
						Q.push({-dis[t], t});
					}
				}
			}
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--) {
		solve s;
		s.init();
	}
	return 0;
}
