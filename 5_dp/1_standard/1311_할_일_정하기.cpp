#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 222222
using namespace std;

int N;
int D[20][20];

void init(){
  cin >> N;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> D[i][j];
}

void solve(){
  int fullMask = (1 << N);
  vector<int> dp(fullMask, MAX);

  dp[0] = 0;
  
  for (int mask = 0; mask < fullMask; ++mask){
    int numAssigned = 0;

    for (int i = 0; i < N; ++i)
      numAssigned += (bool)(mask & (1 << i));
    
    for (int worker = 0; worker < N; ++worker){
      if (mask & (1 << worker)) continue;
      // 이중 포문(노동자와 업무)으로 안해도 되는 이유
      dp[mask | (1 << worker)] = min(dp[mask | (1 << worker)], dp[mask] + D[worker][numAssigned]);
    }
  }

  cout << dp[fullMask - 1];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}