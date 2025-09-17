#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int dp[100001];

int main()
{
  fastio

  cin >> n;

  int answer = -111111111;

  int num;
  for (int i = 1; i <= n; ++i)
  {
    cin >> num;
    dp[i] = max(dp[i - 1] + num, num);
    answer = max(answer, dp[i]);
  }

  cout << answer;
  
  return 0;
}