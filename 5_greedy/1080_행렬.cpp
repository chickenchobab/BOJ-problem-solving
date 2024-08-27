#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
bool A[51][51], B[51][51];

void input(){
  cin >> N >> M;
  string str;
  for (int i = 1; i <= N; ++i){
    cin >> str;
    for (int j = 1; j <= M; ++j){
      A[i][j] = str[j - 1] - '0';
    }
  }
  for (int i = 1; i <= N; ++i){
    cin >> str;
    for (int j = 1; j <= M; ++j){
      B[i][j] = str[j - 1] - '0';
    }
  }
}

void flip(int i, int j){
  for (int di = 0; di < 3; ++di){
    for (int dj = 0; dj < 3; ++dj){
      A[i + di][j + dj] = !A[i + di][j + dj];
    }
  }
}

void solve(){
  int answer = 0;

  for (int i = 1; i <= N - 2; ++i){
    for (int j = 1; j <= M - 2; ++j){
      if (A[i][j] == B[i][j]) continue;

      flip(i, j);
      ++answer;
    }
  }

  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      if (A[i][j] == B[i][j]) continue;
      cout << -1;
      return;
    }
  }

  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}