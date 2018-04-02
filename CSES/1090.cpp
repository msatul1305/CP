#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n, wm, ans;
int p[N];

int main() {
  for(int i = 0; i < n; i++)
    scanf("%d", &p[i]);
  
  sort(p, p + n);
  
  int l = 0, r = n - 1;
  
  while(l <= r) {
    if(p[r] + p[l] <= wm) {
      r--;
      l++;
    } else {
      r--;
    }
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
