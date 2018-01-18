#include <vector>
#include <cstdio>

using namespace std;

namespace fenwick {
	vector<int> T;
	int n = 0;
	void init() {
		T = vector<int>(n + 1, 0);
	}
	void update(int k,int x) {
		while(k <= n) {
			T[k] += x;
			k += k&(-k);
		}
	}
	void update(int l, int r, int x) {
		update(l, x);
		update(r + 1, -x);
	}
	int query(int k) {
		int val = 0;
		while(k >= 1) {
			val += T[k];
			k -= k&(-k);
		}
		return val;
	}
};

int read() {
	int x=0; char ch=getchar_unlocked();
	while(ch<'0' || ch>'9') ch=getchar_unlocked();
	while(ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar_unlocked(); }
	return x;
}

void write(int x) {
	if(x>9) write(x/10);
	putchar_unlocked(x%10+48);
}

int main() {
	int t = read();
	while(t--) {
		int n = read(), u = read();
		fenwick::n = n;
		fenwick::init();
		while(u--) {
			int l = read(), r = read(), v = read();
			fenwick::update(++l, ++r, v);
		}
		int q = read();
		while(q--) {
			int x = read();
			printf("%d\n", fenwick::query(++x));
		}
	}
	return 0;
}
