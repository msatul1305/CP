#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct point {
	long double x, y;
};

long double crossP(point a, point b) {
	return a.x*b.y - a.y*b.x;
}

int n;
long double p, q, ans = 0.0;
vector<point> V;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%Lf %Lf", &p, &q);
		V.push_back({p, q});
	}
	for(int i = 0; i < n; i++) {
		ans += crossP(V[i], V[(i+1) % n]);
	}
	printf("%d\n", (int)fabsl(ans/2));
	return 0;
}
