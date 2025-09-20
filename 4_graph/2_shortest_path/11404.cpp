#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
int dist[101][101];

int main()
{
  fastio

  cin >> n >> m;
  int a, b, c;
  while (m--)
  {
    cin >> a >> b >> c;
    if (!dist[a][b])
    {
      dist[a][b] = c;
    }
    else
    {
      dist[a][b] = min(dist[a][b], c);
    }
  }

  for (int mid = 1; mid <= n; ++mid)
  {
    for (int s = 1; s <= n; ++s)
    {
      for (int e = 1; e <= n; ++e)
      {
        if (s == e) continue;
        if (!dist[s][mid] || !dist[mid][e]) continue;

        if (!dist[s][e])
        {
          dist[s][e] = dist[s][mid] + dist[mid][e];
        }
        else
        {
          dist[s][e] = min(dist[s][e], dist[s][mid] + dist[mid][e]);
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}