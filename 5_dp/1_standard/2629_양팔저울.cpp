#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<int> weights;

void solve(){
  int total = accumulate(begin(weights), end(weights), 0);
  vector<bool> dp(15551, 0);

  dp[0] = 1;

  for (int i = 0; i < n; ++i){
    for (int j = total; j >= 0; --j)
      dp[j + weights[i]] = (bool)(dp[j] | dp[j + weights[i]]);
    for (int j = 0; j <= total; ++j)
      dp[abs(j - weights[i])] = (bool)(dp[j] | dp[abs(j - weights[i])]);
  }

  cin >> m;
  while (m--){
    int measure;
    cin >> measure;
    measure <= total && dp[measure] ? cout << "Y " : cout << "N ";
  }
}

void init(){
  cin >> n;
  weights.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> weights[i];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}