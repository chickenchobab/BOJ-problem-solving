#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
bool queenOnRow[16], queenOnCrossAdd[31], queenOnCrossSub[31];
int answer;

void input(){
  fastio
  cin >> N;
}

void putQueenOnColumn(int col){
  if (col == N + 1) {
    ++answer;
    return;
  }
  for (int row = 1; row <= N; ++row){
    if (queenOnRow[row] || queenOnCrossAdd[row + col - 1] || queenOnCrossSub[col - row + N]) continue;
    queenOnRow[row] = 1;
    queenOnCrossAdd[row + col - 1] = 1;
    queenOnCrossSub[col - row + N] = 1;
    putQueenOnColumn(col + 1);
    queenOnRow[row] = 0;
    queenOnCrossAdd[row + col - 1] = 0;
    queenOnCrossSub[col - row + N] = 0;
  }
}

void solve(){
  putQueenOnColumn(1);
  cout << answer;
}

int main(){
  input();
  solve();
  return 0;
}