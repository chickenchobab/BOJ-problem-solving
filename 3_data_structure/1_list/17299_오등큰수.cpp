#include <iostream>
// #include <algorithm>
// #include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int A[1000001];
int F[1000001];
int NGF[1000001];

int main()
{
  fastio
  
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> A[i];
    ++F[A[i]];
  }

  stack<int> st; // stores indices
  for (int i = N; i > 0; --i)
  {
    while (!st.empty() && F[A[st.top()]] <= F[A[i]])
    {
      st.pop();
    }
    NGF[i] = st.empty() ? -1 : A[st.top()];
    st.push(i);
  }

  for (int i = 1; i <= N; ++i)
  {
    cout << NGF[i] << ' ';
  }

  return 0;
}