#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100050;

void getSA(string &s, vector<int> &p) {
	int n = s.size();
	const int alp = 256;
	
	p.resize(n);
	vector<int> c(n), cnt(N, 0);
	
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	for (int i = 1; i < alp; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	
	c[p[0]] = 0;
	int clas = 1;

	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]])
			clas++;
		c[p[i]] = clas - 1;
	}
	
	vector<int> pn(n), cn(n);
	for (int h = 1; h < n; h = h << 1) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - h;
			if (pn[i] < 0) pn[i] += n;
		}
		
		fill(cnt.begin(), cnt.end(), 0);
		for (int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for (int i = 1; i < clas; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		
		cn[p[0]] = 0;
		clas = 1;
		
		for (int i = 1; i < n; i++) {
			pair<int, int> cur = {c[p[i]], c[(p[i] + h) % n]};
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + h) % n]};
			
			if (cur != prev) clas++;
			cn[p[i]] = clas - 1;
		}
		c.swap(cn);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    s += "$";
    vector<int> ans;
    getSA(s, ans);
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
