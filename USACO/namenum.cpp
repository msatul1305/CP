/*
ID: <HIDDEN>
TASK: namenum
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	string ar[] = {"", "","ABC" , "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
	ifstream names;
	names.open("dict.txt");
	char num;
	vector <int> x;
	while(cin >> num) {
		int temp = num - '0';
		x.push_back(temp);
	}
	size_t nonflag = 1;
	size_t sz = x.size();
	string n;
	while(names >> n) {
		if( (int)n.size() != (int)x.size() )
			continue;
		int count = 0;
		for(int i = 0, j = 0; i < n.size(), j < sz; i++, j++) {
			if(ar[x[j]].find(n[i]) != -1)
				count++;
		}
		if(count == (int)x.size()) {
			nonflag = 0;
			cout  << n << '\n';
		}
	}
	if(nonflag)
		cout << "NONE" << '\n';
	names.close();
	return 0;
}
