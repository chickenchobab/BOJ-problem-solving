#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M, X;
using pii = pair<int, int>;
vector<pii> goingGraph[1001], comingGraph[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> goingDist, comingDist;

void dijstra(int start, vector<pii> graph[], vector<int>& dist)
{
  dist.assign(N + 1, 1111111);

  dist[start] = 0;
  pq.push({dist[start], start});

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

int main()
{
  fastio

  cin >> N >> M >> X;
  int a, b, c;
  while (M--)
  {
    cin >> a >> b >> c;
    comingGraph[a].push_back({c, b});
    goingGraph[b].push_back({c, a});
  }
  
  dijstra(X, comingGraph, comingDist);
  dijstra(X, goingGraph, goingDist);

  int answer = 0;
  
  for (int i = 1; i <= N; ++i)
  {
    answer = max(answer, goingDist[i] + comingDist[i]);
  }

  cout << answer;

  return 0;
}