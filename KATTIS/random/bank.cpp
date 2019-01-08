#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 47;
    
int n, t;
int q[N];
int ans;

bool isFull() {
    for (int i = 0; i < n; i++)
        if (q[i] == -1)
            return 0;
    return 1;
}

void put(int idx, int val) {
    int i = idx;
    while (i >= 0) {
        if (q[i] == -1) {
            q[i] = 0;
            ans += val;
            break;
        }
        i--;
    }
}

int main() {
    memset(q, -1, sizeof(q));
    cin >> n >> t;
    vector< pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(-a, b);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n && !isFull(); i++)
        put(v[i].second, -v[i].first);
    cout << ans << '\n';
    return 0;
}
