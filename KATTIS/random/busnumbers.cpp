#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;

int bus[N];
int n;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &bus[i]);
    sort(bus, bus + n);
    for (int i = 0; i < n; i++) {
        int j = i;
        while (bus[j] + 1 == bus[j + 1]) j++;
        if (j - i >= 2) {
            printf("%d-%d ", bus[i], bus[j]);
            i = j;
        } else {
            printf("%d ", bus[i]);
        }
    }
    return 0;
}
