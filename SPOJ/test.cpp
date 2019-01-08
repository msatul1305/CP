#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<string> v;
    string x = "abca#aabc$";
    for (int i = 0; i < x.size(); i++) {
        v.push_back(x.substr(i, x.size()));
    }
    sort(v.begin(), v.end());
    for (string s : v) {
        cout << s << '\n';
    }
    return 0;
}
