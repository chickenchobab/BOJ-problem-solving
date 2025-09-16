#include <iostream>
#include <algorithm>
// #include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
stack<pair<int, int>> st;

int main(){
  fastio

  cin >> N;

  int height;
  int receiver;
  
  for (int i = 1; i <= N; ++i)
  {
    cin >> height;
    receiver = 0;

    while (!st.empty() && st.top().second <= height)
    {
      st.pop();
    }

    if (!st.empty())
    {
      receiver = st.top().first;
    }

    st.push({i, height});

    cout << receiver << ' ';
  }
  
  return 0;
}