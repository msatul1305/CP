#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 5;

int a[N];
ll dp[N][N];

solve(int i, int j) {
  if (j >= i)
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  return 0;
}
