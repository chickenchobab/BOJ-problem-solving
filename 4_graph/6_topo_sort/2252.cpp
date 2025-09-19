#include <iostream>
// #include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> graph[32001];
int indeg[32001];
queue<int> q;

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
      q.push(i);
    }
  }

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    cout << cur << ' ';

    for (int nxt : graph[cur])
    {
      if (--indeg[nxt] == 0)
      {
        q.push(nxt);
      }
    }
  }

  return 0;
}