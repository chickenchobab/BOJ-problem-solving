#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, k;
int value[101];

void input(){
  fastio
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> value[i];
}

void solve(){
  vector<int> dp(k + 1, 0);

  dp[0] = 1;
  for (int i = 1; i <= n; ++i){
    for (int j = value[i]; j <= k; ++j){
      dp[j] += dp[j - value[i]];
    }
  }

  cout << dp[k];
}

int main(){
  input();
  solve();
  return 0;
}