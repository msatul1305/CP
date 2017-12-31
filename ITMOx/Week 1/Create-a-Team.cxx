#include <bits/stdc++.h>
using namespace std;

double solve(int a, int b, int c) {
	double sol = sqrt(a*a + b*b + c*c);
	return sol;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ar[3][3];
	double ans[6];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++){
			cin >> ar[i][j];
		}
	}
	
	ans[0] = solve(ar[0][0],ar[1][1],ar[2][2]);
	ans[1] = solve(ar[0][0],ar[2][1],ar[1][2]);
	ans[2] = solve(ar[0][1],ar[1][0],ar[2][2]);
	ans[3] = solve(ar[0][1],ar[2][0],ar[1][2]);
	ans[4] = solve(ar[0][2],ar[1][0],ar[2][1]);
	ans[5] = solve(ar[0][2],ar[2][0],ar[1][1]);
	
	double maxans = -1;
	for(int i = 0; i < 6; i++) {
		maxans = max(ans[i],maxans);
	}
	printf("%.16f\n", maxans);
	return 0;
}