#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int offset[100001];
int cost[100001];

int main()
{
  fastio

  cin >> N;
  for (int i = 1; i < N; ++i)
  {
    cin >> offset[i];
  }
  for (int i = 1; i <= N; ++i)
  {
    cin >> cost[i];
  }

  long long answer = 0;

  long long minCost = 1111111111;
  for (int i = 1; i < N; ++i)
  {
    if (cost[i] < minCost)
    {
      minCost = cost[i];
    }

    answer += minCost * offset[i];
  }

  cout << answer;

  return 0;
}