#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int map[501][501];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int dp[501][501];

void init(){
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> map[i][j];
}

int cntArea(int r, int c){
  if (dp[r][c]) return dp[r][c];
  
  int ret = 0;
  for (int d = 0; d < 4; ++d){
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (nr < 1 || nr > n || nc < 1 || nc > n) continue;
    if (map[nr][nc] <= map[r][c]) continue;
    ret = max(ret, cntArea(nr, nc));
  }
  return dp[r][c] = ret + 1;
}

void solve(){
  int answer = 0;

  for (int r = 1; r <= n; ++r)
    for (int c = 1; c <= n; ++c)
      answer = max(answer, cntArea(r, c));

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}