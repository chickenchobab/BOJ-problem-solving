#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, K;
int W[101], V[101];
int dp[100001];

int main()
{
  fastio

  cin >> N >> K;
  for (int i = 1; i <= N; ++i)
  {
    cin >> W[i] >> V[i];
  }

  for (int i = 1; i <= N; ++i)
  {
    // A product should not be duplicated
    for (int j = K; j >= W[i]; --j)
    {
      dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
      // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i])
    }
  }

  cout << dp[K];

  return 0;
}