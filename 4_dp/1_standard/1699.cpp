#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;

void input(){
  fastio
  cin >> N;
}

void solve(){
  vector<int> dp(N + 1, N);
  
  dp[0] = 0;
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j * j <= i; j++){
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }

  cout << dp[N];
}

int main(){
  input();
  solve();
  return 0;
}