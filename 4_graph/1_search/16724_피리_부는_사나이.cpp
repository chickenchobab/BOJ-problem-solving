#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
int direction[1000][1000];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int visitCount[1000][1000];
int curVisitCount;

bool dfs(int r, int c)
{
  visitCount[r][c] = curVisitCount;

  int nr = r + dr[direction[r][c]];
  int nc = c + dc[direction[r][c]];

  if (!visitCount[nr][nc])
  {
    return dfs(nr, nc);
  }
  
  return visitCount[nr][nc] == curVisitCount; // its own cycle
}

int main()
{
  fastio

  cin >> N >> M;
  char d;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
    {
      cin >> d;
      if (d == 'D') direction[i][j] = 0;
      else if (d == 'U') direction[i][j] = 1;
      else if (d == 'R') direction[i][j] = 2;
      else direction[i][j] = 3;
    }
  }

  int answer = 0;

  for (int r = 0; r < N; ++r)
  {
    for (int c = 0; c < M; ++c)
    {
      if (visitCount[r][c]) continue;
      
      ++curVisitCount;

      answer += dfs(r, c);
    }
  }

  cout << answer;

  return 0;
}