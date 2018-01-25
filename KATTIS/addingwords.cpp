#include <bits/stdc++.h>
using namespace std;

string str;
unordered_map<string, int> si;
unordered_map<int, string> is;

int main() {
	#ifdef LUNU
	freopen("in.txt", "r", stdin);
	#endif
	while(getline(cin, str)) {
		if(str == "clear") {
			si.clear();
			is.clear();
		}
		stringstream S;
		S << str;
		string com; S >> com;
		if(com == "def") {
			string var; S >> var;
			int val; S >> val;
			if(si.find(var) == si.end()) {
				si.insert({var, val});
				is.insert({val, var});
			}
			else {
				int tm = si[var];
				si[var] = val;
				is.erase(tm);
				is.insert({val, var});
			}
		}
		else if(com == "calc") {
			string ar[100];
			int n = -1, res = 0, b = 1;
			deque<string> X; deque<int> Y;
			while(S >> ar[++n]) {
				if(ar[n] == "+" || ar[n] == "-") X.push_back(ar[n]);
				else if(ar[n] != "=") {
					auto v = si.find(ar[n]);
					if(v != si.end()) Y.push_back(v->second);
					else b = 0;
				}
			}
			for(; !X.empty() && b; X.pop_front()) {
				int a = Y.front(); Y.pop_front();
				int b = Y.front(); Y.pop_front();
				if(X.front() == "+") Y.push_front(a + b);
				else if(X.front() == "-") Y.push_front(a - b);
			}
			res = Y.front();
			for(int i = 0; i < n; i++) cout << ar[i] << ' ';
			if(b && is.find(res) != is.end()) cout << is.find(res)->second << '\n';
			else cout << "unknown\n";
		}
	}
	return 0;
}
