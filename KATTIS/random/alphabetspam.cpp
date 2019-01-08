#include <bits/stdc++.h>
using namespace std;

const int N = 100007;

double lc, uc, wh, ot, tot;
char s[N];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] == '_') wh += 1;
        else if (s[i] <= 'Z' && s[i] >= 'A') uc += 1;
        else if (s[i] <= 'z' && s[i] >= 'a') lc += 1;
        else ot += 1;
    }
    tot = lc + uc + wh + ot;
    printf("%.19lf\n%.19lf\n%.19lf\n%.19lf\n", wh/tot, lc/tot, uc/tot, ot/tot);
    return 0;
}
