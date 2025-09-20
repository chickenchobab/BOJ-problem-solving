#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m, t, s, g, h;
using pii = pair<int, int>;
vector<pii> graph[2001];
int goals[101];
vector<int> dist;

void dijkstra()
{
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist.assign(n + 1, 111111110);

  dist[s] = 0;
  pq.push({0, s});

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
}

void reset()
{
  for (int i = 1; i <= n; ++i)
  {
    graph[i].clear();
  }
}

int main()
{
  fastio

  int T;
  cin >> T;
  while (T--)
  {
    cin >> n >> m >> t >> s >> g >> h;

    reset();

    int a, b, d;
    for (int i = 0; i < m; ++i)
    {
      cin >> a >> b >> d;

      d *= 2;
      if (a == g && b == h || a == h && b == g)
      {
        --d;
      }

      graph[a].push_back({d, b});
      graph[b].push_back({d, a});
    }

    for (int i = 1; i <= t; ++i)
    {
      cin >> goals[i];
    }

    dijkstra();

    sort(goals + 1, goals + t + 1);

    for (int i = 1; i <= t; ++i)
    {
      if (dist[goals[i]] % 2)
      {
        cout << goals[i] << ' ';
      }
    }

    cout << '\n';
  }

  return 0;
}