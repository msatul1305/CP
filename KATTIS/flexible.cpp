#include <cstdio>
using namespace std;

int n, a, b;
int board[105];
bool yes[105];

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d", &n, &b);
	yes[n] = 1;
	for(int i = 0; i < b; i += 1) {
		scanf("%d", &board[i]);
		yes[board[i]] = yes[n - board[i]] = 1;
	}
	for(int i = 0; i < b; i += 1) {
		for(int j = i + 1; j < b; j += 1) {
			yes[board[j] - board[i]] = 1;
		}
	}
	for(int i = 1; i <= n; i += 1) if(yes[i]) {
		printf("%d%c", i, " \n"[i == n]);
	}
	return 0;
}
