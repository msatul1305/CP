/*
ID: <HIDDEN>
TASK: palsquare
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int B;

bool pal(string x) {
	string t(x);
	reverse(begin(x), end(x));
	return (x == t);
}

void gen(int n) {
	if(B > 10) {
		int sq = n * n;
		string x = "";
		while(sq) {
			int t = sq % B;
			if(t > 9)
				x.push_back(t + 55);
			else
				x.push_back(t + 48);
			sq /= B;
		}
		string o = "";
		while(n) {
			int t = n % B;
			if(t > 9)
				o.push_back(t + 55);
			else
				o.push_back(t + 48);
			n /= B;
		}
		reverse(begin(o), end(o));
		if(pal(x))
			cout << o << " " << x << '\n';
	}
	else if(B < 10) {
		int sq = n * n;
		string x = "";
		while(sq) {
			int t = sq % B;
			x.push_back(t + 48);
			sq /= B;
		}
		string o = "";
		while(n) {
			int t = n % B;
			o.push_back(t + 48);
			n /= B;
		}
		reverse(begin(o), end(o));
		if(pal(x))
			cout << o << " " << x << '\n';
	}
	else {
		int rev = 0;
		int m = n * n;
		int z = m;
		while(m) {
			rev = rev * 10 + m % 10;
			m /= 10;
		}
		if(rev == z)
			printf("%d %d\n", n, rev);
	}
}

int main() {
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	scanf("%d", &B);
	for(int i = 1; i <= 300; i++) {
		gen(i);
	}
	
	return 0;
}
