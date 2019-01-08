#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<int> G[N];
vector<int> ans;
priority_queue<int> Q;

int vis[N], indeg[N];
int n, m;
int a, b;

void kahn() {
    while (!Q.empty()) {
        int f = abs(Q.top()); Q.pop();
        ans.push_back(f);
        for (int cur : G[f]) {
            --indeg[cur];
            if (!indeg[cur])
                Q.push(-cur);
        }
    }
}

int main() {
    for (int i = 0; i < m; i++) {
        scanf("%d %d ", &a, &b);
        G[a].push_back(b);
        ++indeg[b];
    }
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            Q.push(-i);

    kahn();
    if (!accumulate(indeg, indeg + n + 1, 0)) {
        for (int i : ans) {
            printf("%d ", i);
        } puts("");
    } else {
        puts("Sandro fails.");
    }
    return 0;
}
