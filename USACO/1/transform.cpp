/*
ID: <hidden>
TASK: transform
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
char ini[maxn][maxn];
char tra[maxn][maxn];
int eq(char a[][maxn], int d,char b[][maxn]) {
	for(int i = 0; i < d; i++) {
		for(int j = 0; j < d; j++) {
			if(a[i][j] != b[i][j])
				return 0;
		}
	}
	return 1;
}
//1 - 270
//2 - 180
//3 - 90
void anticlock(char ini[][maxn],int d) {
	for(int i = 1; i < d; i++) {
		for(int j = 0; j < i; j++) {
			char temp = ini[i][j];
			ini[i][j] = ini[j][i];
			ini[j][i] = temp;
		}
	}
	int mid = d/2;
	for(int i = 0; i < d; i++) {
		int x = d-1;
		for(int j = 0; j < mid; j++) {
			int temp = ini[j][i];
			ini[j][i] = ini[x][i];
			ini[x][i] = temp;
			x--;
		}
	}
}

void hor(char ini[][maxn],int d) {
	int mid = d/2;
	for(int i = 0; i < d; i++) {
		int x = d-1;
		for(int j = 0; j < mid; j++) {
			int temp = ini[i][j];
			ini[i][j] = ini[i][x];
			ini[i][x] = temp;
			x--;
		}
	}
}

int main() {
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	int n, ans = 3; cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> ini[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> tra[i][j];
		}
	}
	//[1,3]
	bool patch[3] = {false, false, false};
	for(int i = 0; i < 3; i++) {
		anticlock(ini, n);
		if(eq(ini, n, tra)) {
			if(i == 0) {
				patch[2] = true;
			}
			if(i == 1) {
				patch[1] = true;
			}
			if(i == 2) {
				patch[0] = true;
			}
		}
	}
	for(int pt = 0; pt < 3; pt++) {
		if(patch[pt] == true) {
			cout << pt+1 << '\n';
			return 0;
		}
	}
	anticlock(ini, n);//reset
	//[4]
	hor(ini, n);//change
	if(eq(ini, n, tra)) {
		cout << 4 << '\n';
		return 0;
	}
	hor(ini, n);//reset
	
	//[5]
	hor(ini, n);//change
	for(int i = 0; i < 3; i++) {
		anticlock(ini, n);
		if(eq(ini, n, tra)) {
			if(i == 0 || i == 1 || i == 2)
				cout << 5 << '\n';
			return 0;
		}
	}
	//[6]
	if(eq(ini, n, tra)) {
		cout << 6 << '\n';
		return 0;
	}
	cout << 7 << '\n';
	return 0;
}
