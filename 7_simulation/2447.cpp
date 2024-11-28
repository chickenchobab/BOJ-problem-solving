#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
vector<vector<char>> pattern;

void input(){
  cin >> N;
}

void makePattern(int r, int c, int siz){
  if (siz == 1) {
    pattern[r][c] = '*';
    return;
  }

  int newSiz = siz / 3;
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      if (i == 1 && j == 1) continue;
      makePattern(r + i * newSiz, c + j * newSiz, newSiz);
    }
  }
}

void showPattern(){
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      cout << pattern[i][j];
    }
    cout << '\n';
  }
}

void solve(){
  pattern.assign(N, vector<char>(N, ' '));
  makePattern(0, 0, N);
  showPattern();
}

int main(){
  fastio
  input();
  solve();
  return 0;
}