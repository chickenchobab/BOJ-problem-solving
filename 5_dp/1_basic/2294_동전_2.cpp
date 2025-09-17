#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, k;
int coins[101];
vector<int> dp;

int main()
{
  fastio

  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    cin >> coins[i];
  }
  dp.assign(k + 1, k + 1);

  dp[0] = 0;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = coins[i]; j <= k; ++j)
    {
      dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    }
  }

  dp[k] == k + 1 ? cout << -1 : cout << dp[k];

  return 0;
}