#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int maps[5][5];
int r1, c1, r2, c2;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int apple;

void input(){
  fastio
  int num;
  for (int i = 0; i < 5; ++i){
    for (int j = 0; j < 5; ++j){
      cin >> num;
      if (num == 1) ++apple;
      maps[i][j] = num;
    }
  }
  cin >> r1 >> c1 >> r2 >> c2;
}

bool isValid(int r, int c){
  if (r < 0 || r >= 5 || c < 0 || c >= 5) return false;
  return (maps[r][c] != -1);
}

bool findApple(int myR, int myC, int opR, int opC, int myCnt, int opCnt, int blockCnt){

  if (myCnt + opCnt == apple || blockCnt == 2) return myCnt > opCnt;

  bool bestResult = 1; // If ret true the current player loses.
  bool canMove = 0;

  for (int dir = 0; dir < 4; ++dir){
    int newR = myR + dr[dir];
    int newC = myC + dc[dir];
    if (!isValid(newR, newC)) continue;
    if (newR == opR && newC == opC) continue;

    canMove = 1;

    int val = maps[newR][newC];
    maps[myR][myC] = -1;
    maps[newR][newC] = 0;
    bestResult &= findApple(opR, opC, newR, newC, opCnt, myCnt + (val == 1), 0);
    maps[newR][newC] = val;
    maps[myR][myC] = 0;
  }

  if (!canMove) 
    bestResult &= findApple(opR, opC, myR, myC, opCnt, myCnt, blockCnt + 1);
  
  return !bestResult;
}

void solve(){
  cout << (findApple(r1, c1, r2, c2, (maps[r1][c1] == 1), (maps[r2][c2] == 1), 0) > 0);
}

int main(){
  input();
  solve();
  return 0;
}