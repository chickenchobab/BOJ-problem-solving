#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M, K;
char board[2001][2001];
int sum[2001][2001];

void solve(){
  int answer = K * K;

  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      bool isErr = (board[i][j] == 'B' ^ (i + j) & 1 == 1);
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + isErr;
    }
  }

  for (int i = K; i <= N; ++i){
    for (int j = K; j <= M; ++j){
      int numErrInWnd = sum[i][j] - sum[i - K][j] - sum[i][j - K] + sum[i - K][j - K];
      answer = min(answer, min(numErrInWnd, K * K - numErrInWnd));
    }
  }

  cout << answer;
}

void init(){
  cin >> N >> M >> K;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      cin >> board[i][j];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}