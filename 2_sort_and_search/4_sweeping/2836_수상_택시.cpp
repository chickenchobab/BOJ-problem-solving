#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
using pii = pair<int, int>;
vector<pii> reversed;

int main()
{
  fastio

  cin >> N >> M;
  reversed.reserve(N);
  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    if (a > b)
    {
      reversed.push_back({b, a}); // 선긋기
    }
  }

  sort(begin(reversed), end(reversed));

  long long answer = M;

  auto [s, e] = reversed[0];
  for (int i = 1; i < reversed.size(); ++i)
  {
    if (reversed[i].first > e)
    {
      answer += 2 * (e - s);
      s = reversed[i].first;
    }

    e = max(e, reversed[i].second);
  }
  answer += 2 * (e - s);

  cout << answer;

  return 0;
}