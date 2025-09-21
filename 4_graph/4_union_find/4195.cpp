#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> parent;
unordered_map<string, int> names;

int find(int c)
{
  if (parent[c] < 0)
  {
    return c;
  }
  return parent[c] = find(parent[c]);
}

int unite(int a, int b)
{
  a = find(a);
  b = find(b);

  if (a == b)
  {
    return -parent[a];
  }

  if (parent[a] < parent[b])
  {
    parent[a] += parent[b];
    parent[b] = a;
    return -parent[a];
  }
  else
  {
    parent[b] += parent[a];
    parent[a] = b;
    return -parent[b];
  }
}

void reset()
{
  names.clear();
}

int main()
{
  fastio

  int T;
  cin >> T;
  int F;
  while (T--)
  {
    reset();

    cin >> F;

    parent.assign(2 * F + 1, -1);

    string a, b;
    while (F--)
    {
      cin >> a >> b;

      if (!names.count(a))
      {
        names[a] = names.size() + 1;
      }
      if (!names.count(b))
      {
        names[b] = names.size() + 1;
      }
      
      cout << unite(names[a], names[b]) << '\n';
    }
  }

  return 0;
}