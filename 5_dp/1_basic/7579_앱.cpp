#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
int m[101], c[101];
int dp[10001];

int main()
{
  fastio

  cin >> N >> M;
  for (int i = 1; i <= N; ++i)
  {
    cin >> m[i];
  }
  for (int i = 1; i <= N; ++i)
  {
    cin >> c[i];
  }

  int answer = 11111;

  for (int i = 1; i <= N; ++i)
  {
    for (int j = 10000; j >= c[i]; --j)
    {
      dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
      if (dp[j] >= M)
      {
        answer = min(answer, j);
      }
    }
  }

  cout << answer;

  return 0;
}