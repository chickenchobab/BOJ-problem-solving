#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
typedef long long ll;
ll dp[1000][10]; // the number of hill number with ith digit being j(0 ~ 9)

void input(){
  fastio
  cin >> N;
}

void solve(){
  ll answer = 0;

  for (int j = 0; j < 10; ++j) 
    dp[0][j] = 1;

  for (int i = 1; i < N; ++i){
    dp[i][0] = 1;
    for (int j = 1; j < 10; ++j){
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
    }
  }

  for (int j = 0; j < 10; ++j)
    answer = (answer + dp[N - 1][j]) % 10007;
  
  cout << answer;
}

int main(){
  input();
  solve();
  return 0;
}