#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
int h[500][500];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int dp[500][500];

int dfs(int r, int c)
{
  if (dp[r][c] != -1)
  {
    return dp[r][c];
  }

  dp[r][c] = 0;

  for (int d = 0; d < 4; ++d)
  {
    int nr = r + dr[d];
    int nc = c + dc[d];

    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
    if (h[nr][nc] >= h[r][c]) continue;

    dp[r][c] += dfs(nr, nc);
  }

  return dp[r][c];
}

int main()
{
  fastio

  cin >> N >> M;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
    {
      cin >> h[i][j];
      dp[i][j] = -1;
    }
  }

  dp[N - 1][M - 1] = 1;
  cout << dfs(0, 0); 

  return 0;
}