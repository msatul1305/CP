#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 1;

int ans[N];
int n;

int main() {
    double s = 0;
    for (int i = 1; i <= N; i++) {
        s += log10(i);
        ans[i] = ceil(s);
    }
    ans[0] = ans[1] = 1;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", ans[n]);
    }
    return 0;
}
