/*
ID: <hidden>
TASK: ariprog
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 125001;

int bisq[MAX];
int N, M, up;

vector< pair<int, int> > ans;

bool cmp(const pair<int, int> &A, const pair<int, int> &B) {
	return A.second < B.second;
}

void gen() {
	up = M*M * 2;
	for(int i = 0; i <= M; i++) {
		for(int j = i; j <= M; j++) {
			if(i*i + j*j <= MAX)
				bisq[i*i + j*j] = 1;
		}
	}
}

int main() {
	
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	
	scanf("%d\n%d", &N, &M);
	gen();
	for(int a = 0; a <= up; a++) {
		if(bisq[a] != 1) continue;
		for(int n = 1; a + n*(N-1) <= up ; n++) {
			bool f = 1;
			for(int i = 0; i < N; i++) {
				if(a + i*n <= up)
					if(bisq[a + i*n] != 1) {
						f = 0;
						break;
					}
			}
			if(f) {
				ans.push_back({a, n});
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	
	if(ans.size() == 0) {
		printf("NONE\n");
	} else {
		for(int i = 0; i < (int)ans.size(); i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}

