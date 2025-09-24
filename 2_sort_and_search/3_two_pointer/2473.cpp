#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
using ll = long long;
ll arr[5001];

int main()
{
  fastio

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> arr[i];
  }

  sort(arr + 1, arr + N + 1);

  int a, b, c;

  ll sum = 3333333333;
  for (int i = 1; i <= N - 2; ++i)
  {
    int s = i + 1, e = N;

    while (s < e)
    {
      ll curSum = arr[i] + arr[s] + arr[e];

      if (abs(curSum) < sum)
      {
        sum = abs(curSum);
        a = i, b = s, c = e;
      }

      if (curSum > 0)
      {
        --e;
      }
      else
      {
        ++s;
      }
    }
  }

  cout << arr[a] << ' ' << arr[b] << ' ' << arr[c];

  return 0;
}