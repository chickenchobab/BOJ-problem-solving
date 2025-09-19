#include <iostream>
// #include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> graph[32001];
int indeg[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
  fastio

  cin >> N >> M;
  int a, b;
  while (M--)
  {
    cin >> a >> b;
    graph[a].push_back(b);
    ++indeg[b];
  }

  for (int i = 1; i <= N; ++i)
  {
    if (!indeg[i])
    {
      pq.push(i);
    }
  }

  while (!pq.empty())
  {
    int cur = pq.top();
    pq.pop();

    cout << cur << ' ';

    for (int nxt : graph[cur])
    {
      if (--indeg[nxt] == 0)
      {
        pq.push(nxt);
      }
    }
  }

  return 0;
}