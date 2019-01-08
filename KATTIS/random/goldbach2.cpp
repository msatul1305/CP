#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 32000;

bitset<N> np;
vector<int> p;

void sieve() {
    for (int i = 2; i <= N; i++) {
        if (!np[i]) {
            p.push_back(i);
            for (int j = i + i; j <= N; j += i)
                np[j] = true;
        }
    }
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int nearest = upper_bound(p.begin(), p.end(), x) - p.begin();
        stringstream bout;
        int cnt = 0;
        for (int i = 0; i < nearest; i++) {
            for (int j = i; j < nearest; j++) {
                if (p[i] + p[j] == x) {
                    bout << p[i] << "+" << p[j] << '\n';
                    cnt++;
                }
            }
        }
        cout << x << " has " << cnt << " representation(s)\n";
        cout << bout.str();
        cout << '\n';
    }
    return 0;
}
