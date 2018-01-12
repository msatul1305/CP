#include <iostream>
#include <string>
using namespace std;

int t;
long long e;
string b;

long long fast_exp(long long base, long long exp) {
    long long res = 1;
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
	cin >> t;
	while(t--) {
		cin >> b >> e;
		long long ans = fast_exp(b[b.size() - 1] - 48, e);
		if(ans < 1)
			cout << 0 << '\n';
		else
			cout << ans << '\n';

	}
	return 0;
}
