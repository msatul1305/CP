#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

int getL(double x,double y) {
	double ret = sqrt(x*x + y*y);
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	string inp;
	while(getline(cin, inp)) {
		ostringstream ext; ext << inp;
		istringstream extinp(ext.str());
		double a, b, c, x, y, z; extinp >> a >> x >> b >> y >> c >> z;
		double A = getL(b-a, y-x), B = getL(c-b, z-y), C = getL(a-c, z-x);
		cout << A << " " << B << " " << C << '\n';
		double ans = (A*B*C)/sqrt((A+B+C)*(-A+B+C)*(A-B+C)*(A+B-C));
		cout << ans << '\n';
	}
	return 0;
}