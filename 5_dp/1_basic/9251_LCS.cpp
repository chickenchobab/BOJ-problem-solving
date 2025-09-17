#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

string S1, S2;
int dp[1001][1001];

int main()
{
  fastio

  cin >> S1 >> S2;

  for (int i = 1; i <= S1.length(); ++i)
  {
    for (int j = 1; j <= S2.length(); ++j)
    {
      // If there is no branch?
      if (S1[i - 1] == S2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  cout << dp[S1.length()][S2.length()];

  return 0;
}