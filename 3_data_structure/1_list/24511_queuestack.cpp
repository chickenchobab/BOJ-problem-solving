#include <iostream>
#include <algorithm>
// #include <vector>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
bool isStack[100001];
deque<int> dq;

int main(){
  fastio

  cin >> N;

  for (int i = 1; i <= N; ++i)
  {
    cin >> isStack[i];
  }

  int num;
  for (int i = 1; i <= N; ++i)
  {
    cin >> num;
    if (!isStack[i])
    {
      dq.push_back(num);
    }
  }

  cin >> M;
  while (M--)
  {
    cin >> num;
    if (dq.empty())
    {
      cout << num << ' ';
    }
    else
    {
      cout << dq.back() << ' ';
      dq.pop_back();
      dq.push_front(num);
    }
  }
  return 0;
}