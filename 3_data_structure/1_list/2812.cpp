#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K;

void input(){
  fastio
  cin >> N >> K;
}

void solve(){
  string st = "";
  char ch;

  while (N--){
    cin >> ch;
    while (st.size() && st.back() < ch && K) {
      st.pop_back();
      K--;
    }
    st.push_back(ch);
  }
  while (K--) 
    st.pop_back();

  cout << st;
}

int main(){
  input();
  solve();
  return 0;
}