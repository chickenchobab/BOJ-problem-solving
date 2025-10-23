#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF (33333333)
using namespace std;

int N, M, W;
struct edge
{
  int s, e, t;
};
vector<edge> edges;
vector<int> dist;

void reset()
{
  dist.assign(N + 1, INF);
  edges.clear();
}

int main()
{
  fastio

  int T;
  cin >> T;
  int s, e, t;
  while (T--)
  {
    cin >> N >> M >> W;
    reset();
    
    while (M--)
    {
      cin >> s >> e >> t;
      edges.push_back({s, e, t});
      edges.push_back({e, s, t});
    }
    while (W--)
    {
      cin >> s >> e >> t;
      edges.push_back({s, e, -t});
    }

    for (int i = 0; i < N - 1; ++i)
    {
      for (auto [s, e, t] : edges)
      {
        if (dist[e] > dist[s] + t)
        {
          dist[e] = dist[s] + t;
        }
      }
    }

    bool bNegCycle = false;

    for (auto [s, e, t] : edges)
    {
      if (dist[e] > dist[s] + t)
      {
        bNegCycle = true;
        break;
      }
    }

    cout << (bNegCycle ? "YES" : "NO") << '\n';
  }

  return 0;
}