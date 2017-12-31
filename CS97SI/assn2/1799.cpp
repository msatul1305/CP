#include <cmath>
#include <cstdio>
#define M_PI 3.14159265358979323846
using namespace std;
/*
sin(360/2n) = r/(R-r)
*/
int main() {
	int t; scanf("%d", &t);
	int c = 1;
	while(t--) {
		double R, n; scanf("%lf %lf", &R, &n);
		double sinx = sin(M_PI/n);
		double ans = (R*sinx)/((double)1+sinx);
		printf("Scenario #%d:\n%.3f\n\n",c++ , ans);
	}
	return 0;
}