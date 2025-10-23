#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
vector<pair<int, int>> edges;

class DSU
{
public:
  vector<int> parent;
  int numSet;

  DSU(int n) : parent(n + 1, -1), numSet(n) {}

  int find(int x)
  {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
  }

  bool unite(int a, int b)
  {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    if (parent[a] > parent[b]) swap(a, b);
    if (parent[a] == parent[b]) --parent[a];

    parent[b] = a;
    
    --numSet;

    return true;
  }

  bool hasUnconnectedNode()
  {
    for (int i = 1; i < parent.size(); ++i)
    {
      if (parent[i] == -1) return true;
    }
    return false;
  }
};

int main()
{
  fastio
  
  cin >> N;
  char c;
  for (int i = 1; i <= N; ++i)
  {
    for (int j = 1; j <= N; ++j)
    {
      c = cin.get();
      if (c == '\n') c = cin.get();

      if (c == 'Y' && i < j)
      {
        edges.push_back({i, j});
      }
    }
  }

  DSU dsu(N);
  int numSpareEdges = 0;

  for (auto [a, b] : edges)
  {
    if (!dsu.unite(a, b))
    {
      ++numSpareEdges;
    }
  }

  if (N == 1 || (numSpareEdges >= dsu.numSet - 1 && !dsu.hasUnconnectedNode()))
  {
    cout << dsu.numSet - 1;
  }
  else
  {
    cout << -1;
  }

  return 0;
}