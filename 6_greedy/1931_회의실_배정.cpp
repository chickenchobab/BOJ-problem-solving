#include <iostream>
#include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
typedef pair<int, int> pii;
pii meetings[100000];

int main()
{
  fastio

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    cin >> meetings[i].first >> meetings[i].second;
  }

  sort(meetings, meetings + N, [](pii &a, pii &b)->bool{
    if (a.second == b.second)
    {
      return a.first < b.first;
    }
    return a.second < b.second;
  });

  int answer = 1; // first meeting
  int t = meetings[0].second;

  for (int i = 1; i < N; ++i)
  {
    if (meetings[i].first >= t)
    {
      ++answer;
      t = meetings[i].second;
    }
  }

  cout << answer;

  return 0;
}