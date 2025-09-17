#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int A[501];
int dp[501];

int main()
{
  fastio

  cin >> N;
  int a, b;
  for (int i = 1; i <= N; ++i)
  {
    cin >> a >> b;
    A[a] = b;
  }

  int len = 0;

  for (int i = 1; i <= 500; ++i)
  {
    if (!A[i]) continue;

    dp[i] = 1;

    for (int j = 1; j < i; ++j)
    {
      if (A[j] < A[i])
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }

    len = max(len, dp[i]);
  }

  cout << N - len;

  return 0;
}