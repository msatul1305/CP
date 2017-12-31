#include <bits/stdc++.h>
using namespace std;

const int maxn = 31623;//sqrt(1e9)

bool isComposite[maxn];

vector<int> p;

void precomp() {
	isComposite[1] = isComposite[0] = true;
	int a = sqrt(maxn);
	for(int i = 2; i < maxn; i++) {
		if(!isComposite[i]) {
			p.push_back(i);
			for(int j = 2*i; j < maxn; j += i)
				isComposite[j] = true;
		}
	}
}

int main() {
	precomp();
	unordered_set<int> C;
	C.insert(1);
	int t; scanf("%d", &t);
	while(t--) {
		int m, n; scanf("%d %d", &m, &n);
		for(int x : p) {
			int z = max(m/x, 2);
			for(int i = x*z; i <= n; i += x)
				C.insert(i);
		}
		for(int i = m; i <= n; i++) {
			if(C.find(i) == C.end()) printf("%d\n", i);
		}
		printf("\n");
	}
}
