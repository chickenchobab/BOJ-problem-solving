#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
int place[501];
int indeg[501];

int main()
{
  fastio

  int T;
  cin >> T;
  while (T--)
  {
    cin >> n;
    int team;
    for (int i = 1; i <= n; ++i)
    {
      cin >> team;
      place[team] = i;
      indeg[team] = i - 1;
    }

    cin >> m;
    int a, b;
    while (m--)
    {
      cin >> a >> b;
      if (place[a] > place[b]) swap(a, b);

      ++indeg[a];
      --indeg[b];
    }

    bool bPossible = true;
    vector<int> indegOwner(n, 0);

    for (int i = 1; i <= n; ++i)
    {
      if (indegOwner[indeg[i]])
      {
        bPossible = false;
        break;
      }

      indegOwner[indeg[i]] = i;
    }

    if (bPossible)
    {
      for (int team : indegOwner)
      {
        cout << team << ' ';
      }
    }
    else
    {
      cout << "IMPOSSIBLE";
    }
    cout << '\n';
  }

  return 0;
}