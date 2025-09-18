#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int a[100001];
int x;

int main()
{
  fastio

  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
  }
  cin >> x;

  sort(a + 1, a + n + 1);

  int answer = 0;

  int s = 1, e = n;
  while (s < e)
  {
    int res = a[s] + a[e];
    
    if (res == x)
    {
      ++answer;
    }
    
    if (res > x)
    {
      --e;
    }
    else
    {
      ++s;
    }
  }

  cout << answer;

  return 0;
}