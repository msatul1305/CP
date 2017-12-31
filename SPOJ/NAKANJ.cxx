#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int V[8][8];
const int ur[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int uc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	int t; scanf("%d\n", &t);
	while(t--) {
		char a, b, c, d;
		scanf("%c%c %c%c\n", &a, &b, &c, &d);
		a -= 97, b -= 49, c -= 97, d -= 49;
		queue< pair<int, int> > Q;
		Q.push({a, b}); V[a][b] = 0;
		pair<int, int> f = Q.front();
		while(1) {
			f = Q.front(); Q.pop();
			if(f.first == c && f.second == d) {
				printf("%d\n", V[f.first][f.second]);
				break;
			}
			for(int i = 0; i < 8; i++) {
				int x = f.first + ur[i], y = f.second + uc[i];
				if(x <= 7 && y <= 7 && x >= 0 && y >= 0 && !V[x][y])
					Q.push({x, y}), V[x][y] = V[f.first][f.second] + 1;
			}
		}
		memset(V, 0, sizeof(V));
	}
	return 0;
}
