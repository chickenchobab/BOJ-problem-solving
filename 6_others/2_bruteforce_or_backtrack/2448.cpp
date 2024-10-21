#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int N, M;
vector<vector<char>> pattern;

void input(){
  cin >> N;
}

void makePattern(int r, int c, int siz){
  if (siz == 3){
    pattern[r][c] = pattern[r + 1][c - 1] = pattern[r + 1][c + 1] = '*';
    pattern[r + 2][c - 2] = pattern[r + 2][c - 1] = pattern[r + 2][c] = pattern[r + 2][c + 1] = pattern[r + 2][c + 2] = '*';
    return;
  }
  
  int newSiz = siz / 2;
  makePattern(r, c, newSiz);
  makePattern(r + newSiz, c - newSiz, newSiz);
  makePattern(r + newSiz, c + newSiz, newSiz);
}

void showPattern(){
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < M; ++j){
      cout << pattern[i][j];
    }
    cout << '\n';
  }
}

void solve(){
  M = 2 * N - 1;
  pattern.assign(N, vector<char>(M, ' '));
  makePattern(0, N - 1, N);
  showPattern();
}

int main(){
  fastio
  input();
  solve();
  return 0;
}