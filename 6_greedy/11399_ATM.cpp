#include <iostream>
#include <algorithm>
// #include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int P[1000];

int main()
{
  fastio

  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    cin >> P[i];
  }

  sort(P, P + N);

  int answer = 0;

  int waitTime = 0;
  for (int i = 0; i < N; ++i)
  {
    answer += (P[i] + waitTime);
    waitTime += P[i];
  }

  cout << answer;
  
  return 0;
}