#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int wine[10001];
int dp[10001]; // maximum amount of wine including ith wine

void input(){
  fastio
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> wine[i];
}

void solve(){
  dp[1] = wine[1];
  dp[2] = wine[1] + wine[2];
  dp[3] = max(wine[1], wine[2]) + wine[3];

  // limit the number of cases (no more than 3 steps)
  for (int i = 4; i <= n; ++i){
    dp[i] = max(dp[i - 3] + wine[i - 1], dp[i - 2]) + wine[i];
    dp[i] = max(dp[i], dp[i - 4] + wine[i - 1] + wine[i]);
  }

  // find out final cases
  cout << max(dp[n], dp[n - 1]);
}

int main(){
  input();
  solve();
  return 0;
}