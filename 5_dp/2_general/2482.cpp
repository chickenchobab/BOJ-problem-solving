#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DIVISOR (1000000003)
using namespace std;
using ll = long long;

int N, K;
int dp[1000][1000];

void solve(){
  int a, b;  
    
  // 0번을 고른 경우
  for (int start = 0; start < N - 1; ++start)
    dp[0][start] = 1;

  for (int i = 1; i < K; ++i)
    for (int j = 2 * i; j < N - 1; ++j)
      dp[i][j] = (dp[i - 1][j - 2] + dp[i][j - 1]) % DIVISOR;
    
  a = dp[K - 1][N - 2];

  // 0번을 안 고른 경우
  for (int start = 1; start < N; ++start)
    dp[0][start] = start;

  for (int i = 1; i < K; ++i){
    dp[i][2 * i] = 0;
    for (int j = 2 * i + 1; j < N; ++j)
      dp[i][j] = (dp[i - 1][j - 2] + dp[i][j - 1]) % DIVISOR;  
  }
    
  b = dp[K - 1][N - 1];

  cout << (a + b) % DIVISOR; 
}

void init(){
  cin >> N >> K;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}