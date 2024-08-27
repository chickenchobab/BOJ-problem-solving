#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int dp[501][501];

void input(){
  fastio
  cin >> n;
}

// can be done by the reverse order.
void solve(){
  int num;
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= i; ++j){
      cin >> num;
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num;
    }
  }
  int answer = 0;
  for (int i = 1; i <= n; ++i)
    answer = max(dp[n][i], answer);
    
  cout << answer;
}

int main(){
  input();
  solve();
  return 0;
}