#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
using pii = pair<int, int>;
pii lines[1000000];

int main()
{
  fastio

  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    cin >> lines[i].first >> lines[i].second;
  }

  sort(lines, lines + N);

  int answer = 0;

  auto [s, e] = lines[0];
  
  for (int i = 1; i < N; ++i)
  {
    if (lines[i].first > e)
    {
      answer += (e - s);
      s = lines[i].first;
    }

    e = max(e, lines[i].second);
  }

  answer += (e - s);

  cout << answer;

  return 0;
}