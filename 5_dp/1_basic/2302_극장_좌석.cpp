#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
bool bFixed[41];
int dp[41];

int main()
{
  fastio
  
  cin >> N >> M;
  int f;
  while (M--)
  {
    cin >> f;
    bFixed[f] = 1;
  }

  dp[0] = dp[1] = 1;

  for (int i = 2; i <= N; ++i)
  {
    dp[i] = bFixed[i] ? dp[i - 1] : dp[i - 1] + !bFixed[i - 1] * dp[i - 2];
  }

  cout << dp[N];

  return 0;
}