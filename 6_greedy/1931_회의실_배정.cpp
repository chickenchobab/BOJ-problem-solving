#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
using pii = pair<int, int>;
pii meetings[100001];

int main()
{
  fastio

  cin >> N;

  for (int i = 1; i <= N; ++i)
  {
    cin >> meetings[i].first >> meetings[i].second;
  }

  sort(meetings + 1, meetings + N + 1, [](auto &a, auto &b)->bool{
    if (a.second == b.second)
    {
      return a.first < b.first;
    }
    return a.second < b.second;
  });

  int answer = 0;

  int curTime = 0;
  for (int i = 1; i <= N; ++i)
  {
    if (curTime <= meetings[i].first)
    {
      ++answer;
      curTime = meetings[i].second;
    }
  }

  cout << answer;

  return 0;
}