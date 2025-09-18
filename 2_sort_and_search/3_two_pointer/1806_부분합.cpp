#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

// dp가 안되는 이유 : 1912(연속합)과 비교 ㄱㄱ

int N, S;
int arr[100001];

int main()
{
  fastio

  cin >> N >> S;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }

  int answer = N + 1;

  for (int s = 1, e = 1; s <= e && e <= N; ++e)
  {
    while (s <= e && arr[e] - arr[s - 1] >= S)
    {
      answer = min(answer, e - s + 1);
      ++s;
    }
  }

  answer != N + 1 ? cout << answer : cout << 0;

  return 0;
}