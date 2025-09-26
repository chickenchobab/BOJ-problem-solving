#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
using ll = long long;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
  fastio

  cin >> N;
  int siz;
  for (int i = 0; i < N; ++i)
  {
    cin >> siz;
    pq.push(siz);
  }

  long long answer = 0;

  while (pq.size() > 1)
  {
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();

    answer += (a + b);
    pq.push(a + b);
  }

  cout << answer;

  return 0;
}