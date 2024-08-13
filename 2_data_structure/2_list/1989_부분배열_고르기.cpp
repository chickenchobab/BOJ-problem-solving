#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
typedef long long ll;
typedef struct e{
  int localMin; ll localSum; int end; 
}element;

void input(){
  fastio
  cin >> N;
}

void solve(){
  ll maxLocalGrade = 0; 
  int i = 1, j = 1;

  stack<element> st;
  int newLocalMin; ll newLocalSum; 

  for (int k = 1; k <= N; ++k){
    cin >> newLocalMin;
    newLocalSum = 0;

    while (st.size() && st.top().localMin >= newLocalMin){
      auto tmp = st.top();
      st.pop();
      newLocalSum += tmp.localSum;
      if (maxLocalGrade < tmp.localMin * newLocalSum){
        maxLocalGrade = tmp.localMin * newLocalSum;
        i = st.empty() ? 1 : st.top().end + 1;
        j = k - 1;
      }
    }

    newLocalSum += newLocalMin;
    st.push({newLocalMin, newLocalSum, k});
  }

  newLocalSum = 0;
  while (st.size()){
    auto tmp = st.top();
    st.pop();
    newLocalSum += tmp.localSum;
    if (maxLocalGrade < tmp.localMin * newLocalSum){
      maxLocalGrade = tmp.localMin * newLocalSum;
      i = st.empty() ? 1 : st.top().end + 1;
      j = N;
    }
  }

  cout << maxLocalGrade << '\n' << i << ' ' << j;
}

int main(){
  input();
  solve();
  return 0;
}