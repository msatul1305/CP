#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 5;

vector<int> G[N];

ll toLeaf[N], maxLength[N];

void rootAt(int u, int p) {
    for (int v : G[u]) {
        if (v == p) continue;
        rootAt(v, u);
        toLeaf[u] = max(1 + toLeaf[v], toLeaf[u]);
    }
    if ((int)G[u].size() < 2) {
        for (int v : G[u]) if (v != p)
            maxLength[u] += toLeaf[v] + 1;
        return;
    }
    int c1 = 0, c2 = 0;
    for (int v : G[u]) {
        if (v == p) continue;
        if (toLeaf[v] > toLeaf[c1])
            c1 = v;
    }
    for (int v : G[u]) {
        if (v == p || v == c1) continue;
        if (toLeaf[v] > toLeaf[c2])
            c2 = v;
    }
    maxLength[u] = toLeaf[c1] + toLeaf[c2] + 2;
}

int n;

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rootAt(1, 0);
    ll diameter = -1;
    for (int i = 1; i <= n; i++)
        diameter = max(diameter, maxLength[i]);
    cout << diameter << '\n';
    return 0;
}

