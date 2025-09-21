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

bool unite(int a, int b)
{
  a = find(a);
  b = find(b);

  if (a == b) return false;

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

  return true;
}

int main()
{
  fastio

  cin >> n >> m;

  parent.assign(n + 1, -1);

  int answer;
  int a, b;
  for (answer = 1; answer <= m; ++answer)
  {
    cin >> a >> b;
    if (!unite(a, b)) break;
  }
  
  answer <= m ? cout << answer : cout << 0;

  return 0;
}