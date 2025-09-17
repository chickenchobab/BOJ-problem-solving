#include <iostream>
#include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, k;
int coins[101];
int dp[10001];

int main()
{
  fastio

  cin >> n >> k;

  for (int i = 1; i <= n; ++i)
  {
    cin >> coins[i];
  }

  dp[0] = 1;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = coins[i]; j <= k; ++j)
    {
      dp[j] += dp[j - coins[i]];
    }
  }

  cout << dp[k];

  return 0;
}