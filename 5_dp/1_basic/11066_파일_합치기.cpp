#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int K;
vector<vector<int>> dp;
int sum[501];

int main()
{
  fastio

  int T;
  cin >> T;

  while (T--)
  {
    cin >> K;
    dp.assign(K + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= K; ++i)
    {
      cin >> sum[i];
      sum[i] += sum[i - 1];
    }

    for (int l = 2; l <= K; ++l)
    {
      for (int s = 1; s <= K - l + 1; ++s)
      {
        int e = s + l - 1;

        dp[s][e] = 123456789; // 계산

        for (int m = s; m < e; ++m)
        {
          dp[s][e] = min(dp[s][e], dp[s][m] + dp[m + 1][e] + sum[e] - sum[s - 1]);
        }
      }
    }

    cout << dp[1][K] << '\n';
  }

  return 0;
}