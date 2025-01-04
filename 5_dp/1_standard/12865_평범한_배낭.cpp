#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K;
int W[101], V[101];

void solve(){
  vector<int> dp(K + 1, 0);

  for (int i = 1; i <= N; ++i){
    // Same product cannot be duplicated
    for (int j = K; j >= W[i]; --j){
      dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
      // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]])
    }
  }

  cout << dp[K];
}

void init(){
  cin >> N >> K;
  for (int i = 1; i <= N; ++i)
    cin >> W[i] >> V[i];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}