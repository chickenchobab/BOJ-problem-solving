#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int c[5000], p[5000];

void solve(){
  vector<int> dp(10001, 0);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= m - p[i]; ++j)
      dp[j + p[i]] = max(dp[j + p[i]], dp[j] + c[i]);

  cout << dp[m] << '\n';
}

void init(){
  float tmp;
  cin >> n >> tmp;
  m = tmp * 100 + 0.5;
  for (int i = 0; i < n; ++i){
    cin >> c[i] >> tmp;
    p[i] = tmp * 100 + 0.5;
  }
}

int main(){
  fastio
  while (1){
    init();
    if (!n) break;
    solve();
  }
  return 0;
}