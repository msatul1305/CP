#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;

const int N = 2e5 + 5;

int a[N];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >>  a[i];
    s.insert(a[i]);
  }
  while (q--) {
    string qt;
    int x, y;
    cin >> qt >> x >> y;
    if (qt == "!") {
      x -= 1;
      s.erase(s.find_by_order(s.order_of_key(a[x])));
      a[x] = y;
      s.insert(a[x]);
    } else {
      cout << s.order_of_key(y + 1) - s.order_of_key(x) << '\n';
    }
  }
  
  return 0;
}
