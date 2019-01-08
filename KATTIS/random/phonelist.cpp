#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> str(n + 1);
        for (int i = 0; i < n; i++)
            cin >> str[i];
        sort(str.begin(), str.end() - 1);
        bool chk = 0;
        for (int i = 1; i < n && chk == 0; i++) {
            if (str[i].rfind(str[i - 1], 0) == 0) {
                chk = 1;
            }
        }
        if (chk) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
