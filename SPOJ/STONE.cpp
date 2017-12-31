//https://en.wikipedia.org/wiki/Centroid#Centroid_of_a_polygon
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point {
	double x, y;
};

int t;
int n;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	cin >> t;
	cout << fixed; cout.precision(2);
	while(t--) {
		cin >> n;
		vector<point> V;
		for(int i = 0; i < n; i += 1) {
			double tm, tn; cin >> tm >> tn;
			V.push_back({tm, tn});
		}
		double A = 0.0, x = 0.0, y = 0.0;
		for(int i = 0; i < n; i += 1) {
			double tm = (V[i].x * V[(i + 1) % n].y) - V[i].y * V[(i + 1) % n].x;
			A += tm;
			x += (V[i].x + V[(i + 1) % n].x) * tm;
			y += (V[i].y + V[(i + 1) % n].y) * tm;
		}
		x /= 6.0 * (A/2);
		y /= 6.0 * (A/2);
		cout << x << " " << y << '\n';
	}
}
