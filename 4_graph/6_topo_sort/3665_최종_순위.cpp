#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
int ranking[501];
int indeg[501];

int main()
{
  fastio

  int T;
  cin >> T;

  while (T--)
  {
    cin >> n;
    int num;
    for (int i = 1; i <= n; ++i)
    {
      cin >> num;
      ranking[num] = i;
      indeg[num] = i - 1;
    }

    cin >> m;
    int a, b;
    while (m--)
    {
      cin >> a >> b;
      if (ranking[a] > ranking[b])
      {
        swap(a, b);
      }
      ++indeg[a];
      --indeg[b];
    }

    vector<int> team(n, 0);

    bool bPossible = true;

    for (int i = 1; i <= n; ++i)
    {
      if (team[indeg[i]])
      {
        bPossible = false;
        break;
      }

      team[indeg[i]] = i;
    }

    if (bPossible)
    {
      for (int i = 0; i < n; ++i)
      {
        cout << team[i] << ' ';
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