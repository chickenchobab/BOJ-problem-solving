#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX ((1 << 31) - 1)
using namespace std;

int N;
vector<int> p;
vector<vector<int>> dp(500, vector<int>(500));
// interval dp.

void input(){
  fastio
  cin >> N;
  int r, c;

  cin >> r; p.push_back(r);
  for (int i = 1; i < N; ++i){
    cin >> c >> r;
    p.push_back(r);
  }
  cin >> c; p.push_back(c);
}

int getMinMulCnt(int i, int j){
  if (dp[i][j] != MAX)  return dp[i][j];
  if (i == j) return dp[i][j] = 0;

  int ret = MAX;
  for (int k = i; k < j; ++k){
    ret = min(ret, getMinMulCnt(i, k) + getMinMulCnt(k + 1, j) + p[i] * p[k + 1] * p[j + 1]);
  }
  return dp[i][j] = ret;
}

void solve(){
  // cout << getMinMulCnt(0, N - 1);

  for (int m = 0; m < N; ++m)
    dp[m][m] = 0;

  for (int l = 2; l <= N; ++l){
    for (int i = 0; i <= N - l; ++i){
      int j = i + l - 1;
      dp[i][j] = MAX;
      for (int k = i; k < j; ++k)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
    }
  }

  cout << dp[0][N - 1];
}

int main(){
  input();
  solve();
  return 0;
}