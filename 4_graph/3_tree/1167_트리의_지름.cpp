#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int V;
using pii = pair<int, int>;
vector<pii> graph[100001];
int farthest;
int radius;

void dfs(int cur, int prv, int dist)
{
  if (dist > radius)
  {
    radius = dist;
    farthest = cur;
  }

  for (auto [nxt, w] : graph[cur])
  {
    if (nxt == prv) continue;

    dfs(nxt, cur, dist + w);
  }
}

int main()
{
  fastio

  cin >> V;
  int a, b, w;
  for (int i = 1; i <= V; ++i)
  {
    cin >> a;
    while (1)
    {
      cin >> b;
      if (b == -1) break;
      cin >> w;

      graph[a].push_back({b, w});
    }
  }

  dfs(1, 0, 0);
  radius = 0;
  dfs(farthest, 0, 0);

  cout << radius;
  
  return 0;
}