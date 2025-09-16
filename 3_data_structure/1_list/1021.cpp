#include <iostream>
#include <algorithm>
// #include <vector>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
deque<int> dq;

int main(){
  fastio

  cin >> N >> M;
  
  dq.resize(N);
  for (int i = 1; i <= N; ++i)
  {
    dq[i - 1] = i;
  }

  int total = 0;
  
  int num;
  while (M--)
  {
    cin >> num;
    int cnt = 0;

    while (dq.front() != num)
    {
      dq.push_back(dq.front());
      dq.pop_front();
      ++cnt;
    }

    total += min(cnt, (int)dq.size() - cnt);
    dq.pop_front();
  }

  cout << total;

  return 0;
}