#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int A[1000001], NGE[1000001];

void input(){
  fastio
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
}

// Try reverse.
void solve(){
  stack<int> st;

  for (int i = 1; i <= N; ++ i){
    while (st.size() && A[st.top()] <= A[i]){
      NGE[st.top()] = A[i];
      st.pop();
    }
    st.push(i);
  }

  while (st.size()){
    NGE[st.top()] = -1;
    st.pop();
  }

  for (int i = 1; i <= N; ++i)
    cout << NGE[i] << ' ';
}

int main(){
  input();
  solve();
  return 0;
}