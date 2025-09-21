#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M, K;
vector<int> parent;
int cost[10001];

int find(int c)
{
  if (parent[c] < 0) return c;
  return parent[c] = find(parent[c]);
}

void unite(int a, int b)
{
  a = find(a);
  b = find(b);

  if (cost[a] < cost[b])
  {
    parent[b] = a;
  }
  else
  {
    parent[a] = b;
  }
}

int main()
{
  fastio

  cin >> N >> M >> K;

  parent.assign(N + 1, -1);

  for (int i = 1; i <= N; ++i)
  {
    cin >> cost[i];
  }

  int u, v;
  while (M--)
  {
    cin >> u >> v;
    if (find(u) != find(v))
    {
      unite(u, v);
    }
  }

  int totalCost = 0;
  vector<bool> bFriend(N + 1, 0);

  for (int i = 1; i <= N; ++i)
  {
    int p = find(i);

    if (!bFriend[p])
    {
      bFriend[p] = 1;
      totalCost += cost[p];
    }
  }

  totalCost <= K ? cout << totalCost : cout << "Oh no";

  return 0;
}