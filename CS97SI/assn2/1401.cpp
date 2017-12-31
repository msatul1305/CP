#include <iostream>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int t; cin >> t;
	while(t--) {
		int x, f = 5, z = 0;
		cin >> x;
		while(x/f > 0) {
			z += x/f;
			f *= 5;
		}
		cout << z << '\n';
	}
	return 0;
}