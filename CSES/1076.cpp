#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update> iset;

const int N = 2e5 + 5;

iset s;

int a[N];
int n, k;

int main() {
    
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < k; i++)
        s.insert(a[i]);
    
    printf("%d ", *s.find_by_order(k/2 - (k%2 == 0)));
    
    for (int i = 0; i + k < n; i++) {
        s.erase(s.find_by_order(s.order_of_key(a[i])));
        s.insert(a[i + k]);
        printf("%d ", *s.find_by_order(k/2 - (k%2 == 0)));
    }
    
    return 0;
}
