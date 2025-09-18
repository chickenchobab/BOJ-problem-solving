#include <iostream>
#include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, d, k, c;
int belt[30001];
int numToEat[3001];

int main()
{
  fastio

  cin >> n >> d >> k >> c;
  for (int i = 0; i < n; ++i)
  {
    cin >> belt[i];   
  }

  int numTypeToEat = 0;

  for (int i = 0; i < k; ++i)
  {
    if (++numToEat[belt[i]] == 1)
    {
      ++numTypeToEat;
    }
  }
  if (++numToEat[c] == 1)
  {
    ++numTypeToEat;
  }

  int answer = numTypeToEat;

  for (int i = 1; i < n; ++i)
  {
    if (--numToEat[belt[i - 1]] == 0)
    {
      --numTypeToEat;
    }
    if (++numToEat[belt[(i + k - 1) % n]] == 1)
    {
      ++numTypeToEat;
    }

    answer = max(answer, numTypeToEat);
  }

  cout << answer;

  return 0;
}