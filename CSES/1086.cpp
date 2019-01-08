#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll d[10];

void rem(int n) {
  while (n) {
    d[n%10] -= 1;
    n /= 10;
  }
}

bool p() {
  for (int i = 0; i < 10; i++)
    if (d[i] < 0)
      return false;
  return true;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  ll n;
  cin >> n;
  for (int i = 0; i < 10; i++)
    d[i] = n;
  ll ans = 1;
  while (p()) {
    rem(ans);
    ans++;
  }
  cout << ans-2 << '\n';
  return 0;
}
