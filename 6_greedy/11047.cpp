#include <iostream>
#include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, K;
int A[10];

int main()
{
  fastio

  cin >> N >> K;
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
  }

  int answer = 0;

  for (int i = N - 1; i >= 0; --i)
  {
    answer += (K / A[i]);
    K %= A[i];
  }

  cout << answer;

  return 0;
}