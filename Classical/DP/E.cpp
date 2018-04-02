#include <bits/stdc++.h>
using namespace std;

char a[100], b[100];

int ans[100][100];

int main() {
	scanf("%s", a + 1); int sa = strlen(a+1);
	scanf("%s", b + 1); int sb = strlen(b+1);
	cerr << "   ";//
	for(int i = 1; i <= sb; i++) cerr << b[i] << " "; cerr << endl << endl;//	
	for(int i = 1; i <= sa; i++) {
		for(int j = 1; j <= sb; j++) {
			if(j == 1) cerr << a[i] << "  ";//
			if(a[i] == b[j]) {
				ans[i][j] = ans[i-1][j-1] + 1;
			} else {
				ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
			}
			cerr << ans[i][j] << " ";//
		}
		cerr << endl;//

	}
	printf("%d\n", ans[sa][sb]);
	return 0;
}
