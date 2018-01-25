#include <bits/stdc++.h>
using namespace std;

int R[] = {-1, -1, 1, 1, 0, -1, 1, 0};
int C[] = {-1, 1, 1, -1, -1, 0, 0, 1};

char ar[8][8];

int pass(int x, int y) {
	for(int i = 0; i < 8; i += 1) {
		int r = x + R[i], c = y + C[i];
		while(r <= 7 && r >= 0 && c >= 0 && c <= 7) {
			if(ar[r][c] == '*')
				return 0;
			r += R[i], c += C[i];
		}
	}
	return 1;
}

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	int stars = 0;
	for(int i = 0; i < 8; i += 1) {
		for(int j = 0; j < 8; j += 1) {
			cin >> ar[i][j];
			if(ar[i][j] == '*') stars++;
		}
	}
	if(stars != 8) {
		cout << "invalid\n";
		exit(0);
	}
	for(int i = 0; i < 8; i += 1) {
		for(int j = 0; j < 8; j += 1) if(ar[i][j] == '*') {
			if(!pass(i, j)) {
				cout << "invalid\n";
				return 0;
			}
		}
	}
	cout << "valid\n";
	return 0;
}
