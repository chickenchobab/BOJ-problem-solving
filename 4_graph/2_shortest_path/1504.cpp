#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, E;
using pii = pair<int, int>;
vector<pii> graph[801];
int u, v;
int duv, dsu, dsv, due, dve;

void dijkstra(int start)
{
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> dist(N + 1, 222222222);

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty())
  {
    auto [d, cur] = pq.top();
    pq.pop();

    if (dist[cur] < d) continue;

    for (auto [d, nxt] : graph[cur])
    {
      if (dist[nxt] > dist[cur] + d)
      {
        dist[nxt] = dist[cur] + d;
        pq.push({dist[nxt], nxt});
      }
    }
  }

  if (start == u)
  {
    duv = dist[v], dsu = dist[1], due = dist[N];
  }
  else
  {
    dsv = dist[1], dve = dist[N];
  }
}

int main()
{
  fastio

  cin >> N >> E;
  int a, b, c;
  while (E--)
  {
    cin >> a >> b >> c;
    // c *= 2;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  cin >> u >> v;

  dijkstra(u);
  dijkstra(v);

  int result = min(dsu + duv + dve, dsv + duv + due);

  result < 222222222 ? cout << result : cout << -1;

  return 0;
}