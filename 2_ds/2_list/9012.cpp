#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
string str;

void input(){
  fastio
  cin >> T;
}

bool isRightString(){
  stack<char> st;
  int len = str.size();
  for (int i = 0; i < len; ++i){
    char ch = str[i];
    if (ch == ')'){
      if (st.empty() || st.top() != '(') return false;
      st.pop();
    }
    else st.push(ch);
  }
  return st.empty();
}

void solve(){
  while (T--){
    cin >> str;
    if (isRightString()) cout << "YES\n";
    else cout << "NO\n";
  }
}

int main(){
  input();
  solve();
  return 0;
}