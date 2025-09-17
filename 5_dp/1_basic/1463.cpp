#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
vector<int> dp;

int main()
{
  fastio

  cin >> N;
  
  dp.assign(N + 1, 1111111);

  dp[1] = 0;

  for (int i = 1; i < N; ++i)
  {
    if (i * 3 <= N)
    {
      dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }
    if (i * 2 <= N)
    {
      dp[i * 2] = min(dp[i * 2], dp[i] + 1);
    }
    if (i + 1 <= N)
    {
      dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
  }

  cout << dp[N];

  return 0;
}