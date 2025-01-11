#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int s[100001][2];
int dp[100001][2];

void init(){
  cin >> n;
  for (int i = 0; i < 2; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> s[j][i];
}

void solve(){
  dp[1][0] = s[1][0];
  dp[1][1] = s[1][1];

  for (int i = 2; i <= n; ++i){
    dp[i][0] = max(dp[i - 2][1], dp[i - 1][1]) + s[i][0];
    dp[i][1] = max(dp[i - 2][0], dp[i - 1][0]) + s[i][1];
  }

  cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main(){
  fastio
  int T;
  cin >> T;
  while (T--){
    init();
    solve();
  }
  return 0;
}