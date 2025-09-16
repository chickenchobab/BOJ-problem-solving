#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
deque<pair<int, int>> dq;

int main(){
  fastio

  cin >> N;

  int offset;
  for (int i = 1; i <= N; ++i)
  {
    cin >> offset;
    dq.push_back({i, offset});
  }

  for (int i = 1; i <= N; ++i)
  {
    cout << dq.front().first << ' ';
    offset = dq.front().second;
    dq.pop_front();
    
    if (offset > 0)
    {
      --offset;

      while (offset--)
      {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    }
    else 
    {
      offset *= -1;

      while (offset--)
      {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }

  }
  return 0;
}