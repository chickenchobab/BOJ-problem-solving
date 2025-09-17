#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int D, P;
int L[350], C[350];

void solve(){
  vector<int> dp(D + 1, 0);

  for (int i = 0; i < P; ++i){
    dp[L[i]] = max(dp[L[i]], C[i]);
    
    for (int j = D - L[i]; j >= 0; --j){
      if (!dp[j]) continue;
      dp[j + L[i]] = max(dp[j + L[i]], min(dp[j], C[i]));
    }
  }

  cout << dp[D];
}

void init(){
  cin >> D >> P;
  for (int i = 0; i < P; ++i)
    cin >> L[i] >> C[i];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}