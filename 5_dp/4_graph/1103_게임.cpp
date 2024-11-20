#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
char map[51][51];
bool isVisited[51][51];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
vector<vector<int>> dp(51, vector<int>(51, -1));

void init(){
  cin >> N >> M;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      cin >> map[i][j];
}

int dfs(int r, int c, int step){
  if (dp[r][c] != -1) return dp[r][c];

  int ret = 0;

  for (int d = 0; d < 4; ++d){
    int nr = r + (map[r][c] - '0') * dr[d];
    int nc = c + (map[r][c] - '0') * dc[d];
    
    if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
    if (map[nr][nc] == 'H') continue;
    // If found a cycle in current route.
    if (isVisited[nr][nc]){
      cout << -1;
      exit(0);
    }

    isVisited[nr][nc] = 1;
    ret = max(ret, dfs(nr, nc, step + 1));
    isVisited[nr][nc] = 0;
  }

  return dp[r][c] = ret + 1;
}

void solve(){
  isVisited[1][1] = 1;
  cout << dfs(1, 1, 0);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}