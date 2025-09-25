#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M, S, E;
struct edge
{
  int c, a, b;
};
vector<edge> edges;
vector<int> parent;

int find(int c)
{
  if (parent[c] < 0) return c;
  return parent[c] = find(parent[c]);
}

void unite(int a, int b)
{
  a = find(a);
  b = find(b);

  if (parent[a] < parent[b])
  {
    parent[b] = a;
  }
  else
  {
    if (parent[a] == parent[b])
    {
      --parent[b];
    }
    parent[a] = b;
  }
}

int main()
{
  fastio

  cin >> N >> M;
  int A, B, C;
  for (int i = 0; i < M; ++i)
  {
    cin >> A >> B >> C;
    edges.push_back({C, A, B});
  }
  cin >> S >> E;

  sort(begin(edges), end(edges), [](auto &a, auto &b){
    return a.c > b.c;
  });

  parent.assign(N + 1, -1);

  int answer;

  for (auto [c, a, b] : edges)
  {
    if (find(a) == find(b)) continue;

    unite(a, b);
    
    if (find(S) == find(E))
    {
      answer = c;
      break;
    }
  }

  cout << answer;

  return 0;
}