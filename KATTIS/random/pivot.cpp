#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int a[N], mi[N], mx[N];
int n;

int main() {
    scanf("%d", &n);
    int cmi = INT_MAX, cmx = INT_MIN;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cmx = max(cmx, a[i]);
        mx[i] = cmx;
    }
    for (int i = n-1; i >= 0; i--) {
        cmi = min(cmi, a[i]);        
        mi[i] = cmi;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mi[i] && a[i] >= mx[i])
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
