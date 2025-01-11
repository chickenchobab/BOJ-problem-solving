#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
vector<int> dp(11, 0);

void input(){
  fastio
  cin >> T;
}

int cntCombi(int n){
  if (dp[n]) return dp[n];
  return dp[n] = cntCombi(n - 1) + cntCombi(n - 2) + cntCombi(n - 3);
}

void solve(){
  int n;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  while (T--){
    cin >> n;
    cout << cntCombi(n) << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}