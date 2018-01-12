#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e9 + 1;
const int maxn = 31623;// sqrt(N)

bool composite[N];
bool isComposite[maxn];
vector<int> P;

void precomp() {
	isComposite[0] = isComposite[1] = 1;
	for(int i = 2; i <= maxn; i++) {
		if(!isComposite[i]) {
			P.push_back(i);
			for(int j = i*i; j <= maxn; j++) {
				isComposite[i] = 1;
			}
		}
	}
}

int t;
int l, r;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	precomp();
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &l, &r);
		composite[0] = composite[1] = 1;
		for(int i = 0; i < P.size(); i++) {
			int z = max(l/P[i], 2);
			for(int j = z * P[i]; j <= r; j += P[i]) {
				composite[j] = 1;
			}
		}
		for(int i = l; i <= r; i++) {
			if(!composite[i]) printf("%d\n", i);
		}
		puts("");
	}
	return 0;
}
