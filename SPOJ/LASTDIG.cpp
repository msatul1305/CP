#include <cstdio>
using namespace std;

int t;
int b, e;

int fast_exp(int base, int exp) {
    int res = 1;
    while(exp > 0) {
       if(exp % 2 == 1) res = (res*base) % 10;
       base = (base*base) % 10;
       exp /= 2;
    }
    return res % 10;
}

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &b, &e);
		printf("%d\n", fast_exp(b, e));
	}
	return 0;
}
