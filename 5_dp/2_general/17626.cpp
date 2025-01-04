#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;

void init(){
  cin >> n;
}

void solve(){
  vector<int> dp(n + 1);

  dp[0] = 0;

  for (int i = 1; i <= n; ++i){
    dp[i] = i;
    for (int j = 1; j * j <= i; ++j){
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }

  cout << dp[n];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}