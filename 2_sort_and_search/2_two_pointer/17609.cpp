#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
string str;

void init(){
  cin >> str;
}

int checkPalindrome(int s, int e, bool chance){
  while (s <= e){
    if (str[s] != str[e]){
      if (chance) return min(checkPalindrome(s, e - 1, 0), checkPalindrome(s + 1, e, 0));
      return 2;
    }
    --e;
    ++s;
  }
  return !chance;
}

void solve(){
  cout << checkPalindrome(0, str.length() - 1, 1) << '\n';
}

int main(){
  fastio
  cin >> T;
  while (T--){
    init();
    solve();
  }
  return 0;
}