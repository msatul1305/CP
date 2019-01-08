#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;

char s[N];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    if (len <= 8) {
        int num = atoi(s);
        int div;
        for (div = 2; num != 1; div++) num /= div;
        printf("%lld\n", div - 1);
        return 0;
    }
    int i;
    double cur = 0;
    for (i = 1; ceil(cur) != len; i++) {
        cur += log10(i);
    }
    printf("%d\n", i - 1);
    return 0;
}
