#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
using pii = pair<int, int>;
vector<int> parent;
pii coords[1001];
struct edge
{
  double d;
  int a, b;
};
vector<edge> edges;

double dist(pii a, pii b)
{
  double dx = abs(a.first - b.first);
  double dy = abs(a.second - b.second);

  return sqrt(pow(dx, 2) + pow(dy, 2));
}

int find(int c)
{
  if (parent[c] < 0) 
  {
    return c;
  }
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

  for (int i = 1; i <= N; ++i)
  {
    cin >> coords[i].first >> coords[i].second;
    
    for (int j = 1; j < i; ++j)
    {
      edges.push_back({dist(coords[i], coords[j]), i, j});
    }
  }
  
  parent.assign(N + 1, -1);
  
  int a, b;
  for (int i = 0; i < M; ++i)
  {
    cin >> a >> b;
    if (find(a) != find(b))
    {
      unite(a, b);
    }
  }

  sort(begin(edges), end(edges), [](edge &a, edge &b)->bool{
    return a.d < b.d;
  });

  double answer = 0;

  for (auto [d, a, b] : edges)
  {
    if (find(a) != find(b))
    {
      unite(a, b);
      answer += d;
    }
  }

  cout << fixed << setprecision(2) << answer;

  return 0;
}