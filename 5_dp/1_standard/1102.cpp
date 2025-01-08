#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX (16 * 36 + 1)
using namespace std;

int N, P;
int cost[16][16];
int initMask;

void solve(){
  int answer = MAX;
  int fullMask = (1 << N);
  vector<int> dp(1 << N, MAX);

  dp[initMask] = 0;

  for (int mask = initMask; mask < fullMask; ++mask){
    if (dp[mask] == MAX) 
      continue;

    int numWorking = 0;
    for (int i = 0; i < N; ++i)
      numWorking += (bool)(mask & (1 << i));

    if (numWorking >= P)
      answer = min(answer, dp[mask]);

    for (int i = 0; i < N; ++i){
      if (!(mask & (1 << i))) // pick working one
        continue;
      for (int j = 0; j < N; ++j){
        if (mask & (1 << j)) // pick broken one
          continue;
        dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[i][j]);
      }
    }
  }

  cout << (answer == MAX ? -1 : answer);
}

void init(){
  cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> cost[i][j];
  string state;
  cin >> state;
  for (int i = 0; i < N; ++i)
    if (state[i] == 'Y')
      initMask |= (1 << i);
  cin >> P;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}