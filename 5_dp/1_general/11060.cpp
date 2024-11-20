#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int A[1001];

void input(){
  cin >> N;
  for (int i = 1; i <= N; ++i){
    cin >> A[i];
  }
}

void solve(){
  vector<int> dp(N + 1, N);

  dp[1] = 0;
  for (int i = 1; i <= N; ++i){
    for (int j = 0; j <= A[i]; ++j){
      if (i + j <= N){
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }
  }

  cout << (dp[N] == N ? -1 : dp[N]);
}

int main(){
  fastio
  input();
  solve();
  return 0;
}