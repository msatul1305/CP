/*
ID: <HIDDEN>
TASK: milk2
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

bool editor(const pair<int,int> &a,const pair<int,int> &b) {return a.first<b.first;}

int main() {
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int t; cin >> t;
	vector<pair<int,int>> f;
	for(int i=0;i<t;i++) {
		int m,n;
		cin >> m >> n;
		f.push_back(make_pair(m,n));
	}
	sort(f.begin(),f.end(),editor);
	int l=f[0].first,r=f[0].second;
	int lm=r-l,lnm=0;//longest milking ; longest non milking
	for(int i=1;i<t;i++) {
		if(f[i].first > r) {//If there is a gap : LNM
			lm = max(lm,r-l);
			lnm = max(f[i].first-r,lnm);//if the gap is bigger than prev gap : LNM
			r=f[i].second,l=f[i].first;
			}
			r = max(f[i].second,r);
		}
	cout << lm << " " << lnm <<  "\n";
	return 0;
}
