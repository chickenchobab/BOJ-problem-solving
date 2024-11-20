#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int H[501][501];
vector<vector<int>> dp(501, vector<int>(501, -1));
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

void init(){
  cin >> N >> M;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      cin >> H[i][j];
}

int dfs(int r, int c){
  if (dp[r][c] != -1) return dp[r][c];

  int ret = 0;

  for (int d = 0; d < 4; ++d){
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
    if (H[nr][nc] >= H[r][c]) continue;
    ret += dfs(nr, nc);
  }

  return dp[r][c] = ret;
}

void solve(){
  dp[N][M] = 1;
  cout << dfs(1, 1);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}