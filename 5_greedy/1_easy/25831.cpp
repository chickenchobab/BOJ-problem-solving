#include <iostream>
#include <algorithm>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string S;
int cnt, len;

void input(){
  fastio
  cin >> S;
  len = S.length();
}

void count(char c){
  int s = len - 2, e = len - 1;

  while (s >= 0){
    if (S[s] != c) --s;
    if (s == e) --s;
    if (s < 0) break;
    if (S[e] != c + 1) --e;
    if (S[s] == c && S[e] == c + 1) {
      S[s] = S[e] = 'X';
      ++cnt;
    }
  }
}


void solve(){
  count('A');
  count('B');
  cout << cnt;
}

int main(){
  input();
  solve();
  return 0;
}