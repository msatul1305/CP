#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
const int inf = 1e9;

int n, m, x;
int tree[N<<1];

void build() {
    for (int i = n - 1; i >= 1; i--)
        tree[i] = max(tree[2*i], tree[2*i + 1]);
}

int query(int l, int r) {
    int s = -inf;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l%2 == 1) s = max(s, tree[l++]);
        if (r%2 == 0) s = max(s, tree[r--]);        
    }
    return s;
}

void update(int k, int v) {
    k += n;
    tree[k] = v;
    for (k /= 2; k > 0 ; k /= 2)
        tree[k] = max(tree[2*k], tree[2*k + 1]);
}

bool pred(int pos, int piv) {
    if (query(0, pos) >= piv)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> tree[n + i];
    
    build();
    
    for (int i = 0; i < m; i++) {
        cin >> x;
        int l = 0, r = n-1;
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            bool cp = pred(m, x);
            if (cp && m == 0) {
                ans = m;
                break;
            }
            if (!cp) {
                if (m == n-1)
                    break;
                else if (pred(m+1, x)) {
                    ans = m + 1;
                    break;
                } else {
                    l =  m + 1;
                }
            } else {
                r = m - 1;
            }
        }
        if (ans != -1) {
            cout << ans + 1 << " ";
            update(ans, tree[n + ans] - x);
        } else {
            cout << "0 ";
        }
    }
    cout << '\n';
    return 0;
}
