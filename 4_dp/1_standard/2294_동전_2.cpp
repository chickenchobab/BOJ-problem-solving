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
  vector<int> dp(k + 1, 10001);

  dp[0] = 0;
  for (int i = 1; i <= n; ++i){
    for (int j = value[i]; j <= k; ++j){
      dp[j] = min(dp[j], dp[j - value[i]] + 1);
    }
  }

  cout << (dp[k] == 10001 ? -1 : dp[k]);
}

int main(){
  input();
  solve();
  return 0;
}