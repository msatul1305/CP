#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ff first
#define ss second

const int N = 9999;

bool comp[N + 10];

int t, a, b;

bool vis[N + 10];

vector<int> primes;
vector<int> G[N + 10];

bool diff(int a, int b) {
	int c = 0;
	for(; a && b; a /= 10, b /= 10) {
		if(a % 10 != b % 10) c++;
	}
	return c == 1;
}

void graph() {
	for(int i = 0; i < (int)primes.size(); i++)
		for(int j = i + 1; j < (int)primes.size(); j++)
			if(diff(primes[i], primes[j])) {
				G[primes[i]].push_back(primes[j]);
				G[primes[j]].push_back(primes[i]);
			}
}

void sieve() {
	for(int i = 2; i <= N; i++)
		if(comp[i] == 0) {
			if(i > 999) primes.push_back(i);
			for(int j = i*i; j <= N; j += i) {
				comp[j] = 1;
			}
		}
}

int bfs(int s, int d) {
	vis[s] = 1;
	queue< pair<int, int> > Q;
	Q.push({s, 0});
	while(!Q.empty()) {
		auto f = Q.front(); Q.pop();
		if(f.ff == d)
			return f.ss;
		for(int i = 0; i < (int)G[f.ff].size(); i++) {
			int x = G[f.ff][i];
			if(!vis[x]) {
				vis[x] = 1;
				Q.push({x, f.ss + 1});
			}
		}
	}
	return -1;
}

int main() {
	sieve();
	graph();
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		int ans = bfs(a, b);
		if(ans == -1) {
			puts("Impossible");
		} else {
			printf("%d\n", ans);
		}
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
