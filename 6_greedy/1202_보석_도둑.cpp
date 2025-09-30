#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, K;
using pii = pair<int, int>;
pii info[300001];
int C[300001];
priority_queue<int> pq;

int main()
{
  fastio

  cin >> N >> K;
  for (int i = 1; i <= N; ++i)
  {
    cin >> info[i].first >> info[i].second;
  }
  for (int i = 1; i <= K; ++i)
  {
    cin >> C[i];
  }

  sort(info + 1, info + N + 1);
  sort(C + 1, C + K + 1);

  long long answer = 0;

  int idx = 1;

  for (int i = 1; i <= K; ++i)
  {
    while (idx <= N && info[idx].first <= C[i])
    {
      pq.push(info[idx].second);
      ++idx;
    }

    if (!pq.empty())
    {
      answer += pq.top();
      pq.pop();
    }
  }

  cout << answer;

  return 0;
}