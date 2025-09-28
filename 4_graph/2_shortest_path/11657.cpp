#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
struct edge
{
  int a, b, c;
};
vector<edge> edges;
vector<long long> dist;
#define INF (66666666)

int main()
{
  fastio

  cin >> N >> M;
  int a, b, c;
  while (M--)
  {
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  dist.assign(N + 1, INF);
  dist[1] = 0;

  for (int i = 0; i < N - 1; ++i)
  {
    for (auto [a, b, d] : edges)
    {
      if (dist[a] == INF) continue;

      if (dist[b] > dist[a] + d)
      {
        dist[b] = dist[a] + d;
      }
    }
  }

  bool bHasPath = true;

  for (auto [a, b, d] : edges)
  {
    if (dist[a] == INF) continue;

    if (dist[b] > dist[a] + d)
    {
      bHasPath = false;
    }
  }

  if (bHasPath)
  {
    for (int i = 2; i <= N; ++i)
    {
      cout << (dist[i] != INF ? dist[i] : -1) << '\n';
    }
  }
  else
  {
    cout << -1;
  }

  return 0;
}