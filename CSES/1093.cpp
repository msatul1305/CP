#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll n, tar;
ll dp[505][130000];

ll solve(ll cur, ll sum) {
  if (cur == n) {
    if (sum == tar)
      return 1;
    else
      return 0;
  }
  if (sum > tar)  
    return 0;
  if (dp[cur][sum] == -1)
    dp[cur][sum] = (solve(cur + 1, sum) + solve(cur + 1, sum + cur)) % mod;
  return dp[cur][sum];
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  memset(dp, -1, sizeof(dp));
  cin >> n;
  tar = n*(n+1)/2;
  if (tar % 2) {
    cout << 0 << '\n';
  } else {
    tar /= 2;
    cout << solve(1, 0) << '\n';
  }
  return 0;
}
