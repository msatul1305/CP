/*
ID: <hidden>
TASK: wormhole
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

const int NAX = 12 + 1;

int N;
int X[NAX], Y[NAX];
int other[NAX];
int adj[NAX];

bool cycle() {
  for(int i = 1; i <= N; i++) {
    int pos = i;
    for(int j = 0; j < N; j++)
      pos = adj[other[pos]]; 
    if(pos != 0) return true;
  }
  return false;
}

int solve() {
  int i, total = 0;
  for(i = 1; i <= N; i++)
    if(other[i] == 0) break;
  
  if(i > N) {
    if(cycle())
      return 1;
    else
      return 0;
  }
  
  for(int j = i + 1; j <= N; j++) {
    if(other[j] == 0) {
      other[j] = i;
      other[i] = j;
      total += solve();
      other[i] = other[j] = 0;
    }
  }
  
  return total;
}

int main () {
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);
  
  scanf("%d", &N);
	
  for(int i = 1; i <= N; i++)
    scanf("%d %d", &X[i], &Y[i]);

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      if(Y[i] == Y[j] && X[j] > X[i])
        if(X[j] - X[i] < X[adj[i]] - X[i] || adj[i] == 0)
          adj[i] = j;
  
  printf("%d\n", solve());
  return 0;
}
