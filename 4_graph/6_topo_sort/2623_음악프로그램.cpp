#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> graph[1001];
int indeg[1001];

int main()
{
  fastio

  cin >> N >> M;
  int num, a, b;
  while (M--)
  {
    cin >> num;
    cin >> a;
    for (int i = 1; i < num; ++i)
    {
      cin >> b;
      ++indeg[b];
      graph[a].push_back(b);
      a = b;
    }
  }

  queue<int> q;

  for (int i = 1; i <= N; ++i)
  {
    if (!indeg[i])
    {
      q.push(i);
    }
  }

  vector<int> nodes;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();

    nodes.push_back(cur);

    for (int nxt : graph[cur])
    {
      if (--indeg[nxt] == 0)
      {
        q.push(nxt);
      }
    }
  }

  if (nodes.size() == N)
  {
    for (int n : nodes)
    {
      cout << n << '\n';
    }
    return 0;
  }

  cout << 0;

  return 0;
}