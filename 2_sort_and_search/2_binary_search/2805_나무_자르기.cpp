#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
int heights[1000000];

bool doesMeetCondition(int h)
{
  int sum = 0;

  for (int i = 0; i < N; ++i)
  {
    sum += max(heights[i] - h, 0);
    if (sum >= M)
    {
      return true;
    }
  }

  return sum >= M;
}

int main()
{
  fastio

  cin >> N >> M;
  for (int i = 0; i < N; ++i)
  {
    cin >> heights[i];
  }

  int answer = 0;

  int l = 0, r = 1000000000;
  while (l <= r)
  {
    int m = (l + r) / 2;

    if (doesMeetCondition(m))
    {
      answer = max(answer, m);
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }

  cout << answer;

  return 0;
}