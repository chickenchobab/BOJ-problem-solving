#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
vector<vector<int>> dp(10001, vector<int>(3, -1)); 
// 1 and under, 2 and under, 3 and under

void input(){
  fastio
  cin >> T;
}

int cntCombi(int n, int c){
  if (dp[n][c] != -1) return dp[n][c];
  
  // find out deduped cases
  if (c == 0) return dp[n][0] = cntCombi(n - 1, 0);
  if (c == 1) return dp[n][1] = cntCombi(n - 2, 0) + cntCombi(n - 2, 1);
  if (c == 2) return dp[n][2] = cntCombi(n - 3, 0) + cntCombi(n - 3, 1) + cntCombi(n - 3, 2);
}

void solve(){
  for (int i = 0; i < 3; ++i)
    dp[1][i] = dp[2][i] = dp[3][i] = 0;

  dp[1][0] = 1;
  dp[2][0] = dp[2][1] = 1;
  dp[3][0] = dp[3][1] = dp[3][2] = 1;

  int n;
  while (T--){
    cin >> n;
    cout << cntCombi(n, 0) + cntCombi(n, 1) + cntCombi(n, 2) << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}