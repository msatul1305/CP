/*
ID: <HIDDEN>
TASK: barn1
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> s;
vector<int> gaps;
bool stall[205];

int M, S, C;
int t;

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	scanf("%d%d%d", &M, &S, &C);
	for(int i = 0; i < C; i++) {
		scanf("%d", &t);
		s.push_back(t);
		stall[t] = 1;
	}
	sort(begin(s), end(s));
	int c = 0;
	for(int i = s[0]; i < s[s.size()-1]; i++) {
		if(!stall[i]) {
			while(stall[i++] == 0) c++;
			gaps.push_back(c); c = 0; i--;
		}
	}
	sort(begin(gaps), end(gaps), greater<int>()); --M, t = 0;
	for(int i = 0; i < gaps.size(); i++) {
		if(M) M--;
		else t += gaps[i];
	}
	printf("%d\n", t + C);
	return 0;
}
