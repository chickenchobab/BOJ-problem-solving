#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int map[5][5];
int r1, c1, r2, c2;
int totalApple;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

void init(){
  for (int r = 0; r < 5; ++r){
    for (int c = 0; c < 5; ++c){
      cin >> map[r][c];
      totalApple += (map[r][c] == 1);
    }
  }
  cin >> r1 >> c1 >> r2 >> c2;
}

bool isValid(int r, int c){
  if (r < 0 || r >= 5 || c < 0 || c >= 5) return false;
  if (map[r][c] == -1) return false;
  return true;
}

bool eatMoreApple(int myR, int myC, int opR, int opC, int myApple, int opApple, int numBlocked){

  if (numBlocked == 2 || myApple + opApple == totalApple)
    return myApple > opApple;
  
  bool canWin = 0;
  bool canMove = 0;

  for (int dir = 0; dir < 4; ++dir){
    int newR = myR + dr[dir];
    int newC = myC + dc[dir];

    if (isValid(newR, newC) && (newR != opR || newC != opC)){
      canMove = 1;

      int numApple = map[newR][newC];
      map[myR][myC] = -1;
      map[newR][newC] = 0;
      canWin = max(canWin, !eatMoreApple(opR, opC, newR, newC, opApple, myApple + (numApple == 1), 0));
      map[myR][myC] = 0;
      map[newR][newC] = numApple;
    }
  }

  if (!canMove)
    canWin = max(canWin, !eatMoreApple(opR, opC, myR, myC, opApple, myApple, numBlocked + 1));
  return canWin;
}

void solve(){
  cout << eatMoreApple(r1, c1, r2, c2, 0, 0, 0);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}