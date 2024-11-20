#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
vector<vector<int>> dp(100001, vector<int>(3, -1));

void input(){
  fastio
  cin >> T;
}

int cntCombi(int n, int head){
  if (dp[n][head] != -1) return dp[n][head];
  return dp[n][head] = (cntCombi(n - head - 1, (head + 1) % 3) + cntCombi(n - head - 1, (head + 2) % 3)) % 1000000009;
}

void solve(){
  int n;
  dp[1][0] = 1;
  dp[1][1] = dp[1][2] = 0;
  dp[2][1] = 1;
  dp[2][0] = dp[2][2] = 0;
  dp[3][0] = dp[3][1] = dp[3][2] = 1;

  while (T--){
    cin >> n;
    int res = cntCombi(n, 0);
    res = (res + cntCombi(n, 1)) % 1000000009;
    res = (res + cntCombi(n, 2)) % 1000000009;
    cout << res << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}