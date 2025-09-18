#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

using ll = long long;
ll N, K;

ll countBelow(ll num) 
{
  ll numBelow = 0;

  for (int i = 1; i <= N; ++i)
  {
    numBelow += min(num / i, N);
  }

  return numBelow;
}

int main()
{
  fastio
  
  cin >> N >> K;

  ll answer = 0;

  ll l = 1, r = N * N;
  while (l <= r)
  {
    ll m = (l + r) / 2;

    if (countBelow(m) < K)
    {
      l = m + 1;
    }
    else
    {
      answer = m;
      r = m - 1;
    }
  }

  cout << answer;

  return 0;
}