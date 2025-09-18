#include <iostream>
#include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int att[100001];

int main()
{
  fastio

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> att[i];
  }

  sort(att + 1, att + N + 1);

  int small, large;
  int minAbs = 2000000000;

  int s = 1, e = N;
  while (s < e)
  {
    int res = att[s] + att[e];

    if (abs(res) < minAbs)
    {
      minAbs = min(minAbs, abs(res));
      small = s;
      large = e;
    }

    if (res > 0)
    {
      --e;
    }
    else
    {
      ++s;
    }
  }

  cout << att[small] << ' ' << att[large];

  return 0;
}