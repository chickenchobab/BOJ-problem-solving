#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int C, N;
int cost[21], effect[21];

void init(){
  cin >> C >> N;
  for (int i = 1; i <= N; ++i)
    cin >> cost[i] >> effect[i];
}

void solve(){
  int answer = 111111;
  vector<int> dp(1111, 111111);

  dp[0] = 0;

  for (int c = 0; c < C; ++c)
    for (int i = 1; i <= N; ++i)
      dp[c + effect[i]] = min(dp[c + effect[i]], dp[c] + cost[i]);

  for (int c = C; c < 1111; ++c)
    answer = min(answer, dp[c]);
  
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}