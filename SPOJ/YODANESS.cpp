#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, t;

vector<int> bit(30005);

void add(int k, int x) {
    while (k <= n) {
        bit[k] += x;
        k += k & -k;
    }
}

int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        fill(bit.begin(), bit.end(), 0);
        unordered_map<string, int> mp;
        vector<string> ss;
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            ss.push_back(s);
        }
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        for (string &s : ss)
            v.push_back(mp[s]);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += i - sum(v[i]) - 1;
            add(v[i], 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
