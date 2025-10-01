#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
vector<int> p;
int dp[500][500];

int main()
{
  fastio

  cin >> N;
  int r, c;
  cin >> r;
  p.push_back(r);
  for (int i = 1; i < N; ++i)
  {
    cin >> c >> r;
    p.push_back(r);
  }
  cin >> c;
  p.push_back(c);

  for (int l = 2; l <= N; ++l)
  {
    for (int s = 0; s <= N - l; ++s)
    {
      int e = s + l - 1;

      dp[s][e] = (1 << 31) - 1;

      for (int m = s; m < e; ++m)
      {
        dp[s][e] = min(dp[s][e], dp[s][m] + dp[m + 1][e] + p[s] * p[m + 1] * p[e + 1]);
      }
    }
  }

  cout << dp[0][N - 1];

  return 0;
}