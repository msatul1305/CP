#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 1e6+10;
bool isComposite[maxn];

void precomp() {
	isComposite[0] = isComposite[1] = 1;
	for(int i = 2; i < sqrt(maxn); i++) {
		if(isComposite[i] == 0) {
			for(int j = 2*i; j < maxn; j += i) {
				isComposite[j] = 1;
			}
		}
	}
}

int main() {
	precomp();
	freopen("in.txt", "r", stdin);
	while(1) {
		int n; scanf("%d", &n);
		if(n == 0) break;
		for(int i = n-1; i >= 2; i--) {
			if(isComposite[i] == 0 && isComposite[n-i] == 0){
				printf("%d = %d + %d\n", n, n-i, i);
				break;
			}
		}
	}
	return 0;
}