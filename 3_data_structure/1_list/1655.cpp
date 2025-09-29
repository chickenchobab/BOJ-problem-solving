#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;

int main()
{
  fastio

  cin >> N;

  l.push(-10001);
  r.push(10001);

  int num;
  while (N--)
  {
    cin >> num;
    
    if (l.size() == r.size())
    {
      if (r.top() < num)
      {
        l.push(r.top());
        r.pop();
        r.push(num);
      }
      else
      {
        l.push(num);
      }
    }
    else
    {
      l.push(num);
      r.push(l.top());
      l.pop();
    }

    cout << l.top() << '\n';
  }

  return 0;
}