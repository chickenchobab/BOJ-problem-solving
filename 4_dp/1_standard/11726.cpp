#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int dp[1001];

void input(){
  fastio
  cin >> n;
}

void solve(){
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i){
    // current column cases
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
  }
  cout << dp[n];
}

int main(){
  input();
  solve();
  return 0;
}