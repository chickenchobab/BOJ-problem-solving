#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, S;
int arr[100001];

int main()
{
  fastio

  cin >> N >> S;

  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i];
  }

  int answer = N + 1;

  int sum = 0;
  for (int s = 1, e = 1; e <= N; ++e)
  {
    sum += arr[e];

    while (s <= e && sum >= S)
    {
      answer = min(answer, e - s + 1);
      sum -= arr[s];
      ++s;
    }
  }

  answer != N + 1 ? cout << answer : cout << 0;

  return 0;
}