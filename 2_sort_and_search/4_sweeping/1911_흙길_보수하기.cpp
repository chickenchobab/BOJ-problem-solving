#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, L;
pair<int, int> pools[10000];

int main()
{
  fastio

  cin >> N >> L;
  for (int i = 0; i < N; ++i)
  {
    cin >> pools[i].first >> pools[i].second;
  }

  sort(pools, pools + N);

  int answer = 0;
  int boundary = pools[0].first;

  int cnt;
  for (int i = 0; i < N; ++i)
  {
    if (pools[i].second <= boundary) continue;

    cnt = (pools[i].second - max(boundary, pools[i].first)) / L;
    
    boundary = max(boundary, pools[i].first) + cnt * L;
    answer += cnt;

    if (boundary < pools[i].second)
    {
      ++answer;
      boundary += L;
    }

    // cout << answer << ' ' << boundary << endl;
  }

  cout << answer;

  return 0;
}