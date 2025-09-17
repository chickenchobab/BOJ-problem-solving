#include <iostream>
#include <algorithm>
// #include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, K;
typedef pair<int, int> pii;
pii J[300000];
int C[300000];

int main()
{
  fastio

  cin >> N >> K;
  for (int i = 0; i < N; ++i)
  {
    cin >> J[i].first >> J[i].second;
  }
  for (int i = 0; i < K; ++i)
  {
    cin >> C[i];
  }

  sort(J, J + N);
  sort(C, C + K);

  long long answer = 0;
  priority_queue<int> pq;

  for (int i = 0, j = 0; j < K; ++j)
  {
    while (i < N && J[i].first <= C[j])
    {
      pq.push(J[i++].second);
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