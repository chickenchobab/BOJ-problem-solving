#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
vector<int> parent;

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

  if (a == b)
  {
    return;
  }

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

  cin >> n >> m;

  parent.assign(n + 1, -1);

  int c, a, b;
  while (m--)
  {
    cin >> c >> a >> b;
    if (c)
    {
      find(a) == find(b) ? cout << "YES" : cout << "NO";
      cout << '\n';
    }
    else
    {
      unite(a, b);
    }
  }

  return 0;
}