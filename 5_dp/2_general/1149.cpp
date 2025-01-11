#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int cost[1001][3];

void solve(){
  vector<vector<int>> dp;
  dp.assign(N + 1, vector<int>(3, 0));

  for (int i = 1; i <= N; ++i){
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
  }

  cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}

void init(){
  cin >> N;
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> cost[i][j];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}