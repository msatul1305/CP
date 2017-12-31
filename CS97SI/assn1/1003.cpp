#include<iostream>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	float t = 9.99;
	while(1) {
		cin >> t;
		if(t == 0.00)
			break;
		int i;
		float f = 0;
		for(i = 2; ;i++) {
			f  += 1/(float)i;
			if(f > t)
				break;
		}
		cout << i-1 << " card(s)" << '\n';
	}
	return 0;
}