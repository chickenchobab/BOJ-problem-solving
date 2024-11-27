#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int T; 
string s;
stack<char> l, r;

void init(){
  cin >> s;
}

void print(){
  string str;
  while (!l.empty()){
    r.push(l.top());
    l.pop();
  }
  while (!r.empty()){
    str.push_back(r.top());
    r.pop();
  }
  cout << str << '\n';
}

void solve() {
  char ch;
  for (int i = 0; i < s.length(); ++i) {
    ch = s[i];
    if (ch == '\n') break;

    if (ch == '<'){
      if (!l.empty()){
        r.push(l.top());
        l.pop();
      }
    }
    else if (ch == '>'){
      if (!r.empty()){
        l.push(r.top());
        r.pop();
      }
    }
    else if (ch == '-'){
      if (!l.empty())
        l.pop();
    }
    else {
      l.push(ch);
    }
  }

  print();
}

int main() {
  fastio
  cin >> T;
  cin.ignore();
  while (T--) {
    init();
    solve();
  }
  return 0;
}
