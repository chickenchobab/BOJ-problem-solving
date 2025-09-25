#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M, S, E;
using pii = pair<int, int>;
vector<pii> graph[10001];
priority_queue<pii> pq;
vector<int> weight;

void dijkstra(int start)
{
  weight.assign(N + 1, 0);

  weight[start] = 1111111111;
  pq.push({weight[start], start});

  while (!pq.empty())
  {
    auto [u, cur] = pq.top();
    pq.pop();

    if (weight[cur] > u) continue;

    for (auto [v, nxt] : graph[cur])
    {
      int cost = min(u, v); // min weight in the path to here

      if (weight[nxt] < cost)
      {
        weight[nxt] = cost;
        pq.push({weight[nxt], nxt});
      }
    }
  }
}

int main()
{
  fastio

  cin >> N >> M;
  int a, b, c;
  while (M--)
  {
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  cin >> S >> E;

  dijkstra(S);
  
  cout << weight[E];

  return 0;
}