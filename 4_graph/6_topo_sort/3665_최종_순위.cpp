#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int T;
int n, m;
int indeg[501];
queue<int> q;

int main()
{
  fastio

  cin >> T;
  while (T--)
  {
    cin >> n;
    int team;
    for (int i = 1; i <= n; ++i)
    {
      cin >> team;
      indeg[team] = i - 1;
    }

    cin >> m;
    int a, b;
    while (m--)
    {
      cin >> a >> b;
      if (indeg[a] < indeg[b])
      {
        ++indeg[a];
        --indeg[b];
      }
      else
      {
        --indeg[a];
        ++indeg[b];
      }
    }

    vector<int> ranking(n + 1, 0);
    
    bool bPossible = 1;

    for (int i = 1; i <= n; ++i)
    {
      if (!ranking[indeg[i]])
      {
        ranking[indeg[i]] = i;
      }
      else // indegree should be 01234
      {
        bPossible = 0;
        break;
      }
    }

    if (bPossible)
    {
      for (int i = 0; i < n; ++i)
      {
        cout << ranking[i] << ' ';
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