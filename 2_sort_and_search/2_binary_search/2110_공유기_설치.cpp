#include <iostream>
#include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, C;
int pos[200000];

bool doesMeetCondition(int d)
{
  int recentPos = pos[0];
  int cnt = 1;

  for (int i = 1; i < N; ++i)
  {
    if (pos[i] - recentPos >= d)
    {
      recentPos = pos[i];
      if (++cnt == C)
      {
        return true;
      }
    }
  }

  return false;
}

int main()
{
  fastio

  cin >> N >> C;
  for (int i = 0; i < N; ++i)
  {
    cin >> pos[i];
  }

  sort(pos, pos + N);

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