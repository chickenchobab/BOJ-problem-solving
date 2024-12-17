#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
map<int, int> line;

void init(){
  cin >> n;
  int a, b;
  for (int i = 0; i < n; ++i){
    cin >> a >> b;
    line[a] = b;
  }
}

void solve(){
  int len = 0;
  vector<int> dp(501);

  for (auto i = begin(line); i != end(line); ++i){
    dp[(*i).first] = 1;
    for (auto j = begin(line); j != i; ++j){
      if ((*j).second < (*i).second){
        dp[(*i).first] = max(dp[(*i).first], dp[(*j).first] + 1);
        len = max(len, dp[(*i).first]);
      }
    }
  }

  cout << n - len;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}