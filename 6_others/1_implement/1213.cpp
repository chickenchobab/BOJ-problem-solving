#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string name;
vector<char> res;
char center;

void input(){
  cin >> name;
}

void success(bool isOdd){
  for (int i = 0; i < res.size(); ++i){
    cout << res[i];
  }
  if (isOdd) cout << center;
  for (int i = res.size() - 1; i >=0; --i){
    cout << res[i];
  }
}

void fail(){
  cout << "I'm Sorry Hansoo";
  exit(0);
}

void solve(){
  int oddCnt = 0;
  vector<int> cnt(26, 0);

  for (char &c : name) cnt[c - 'A']++;

  for (int c = 0; c < 26; ++c){
    if (cnt[c] % 2) {
      center = c + 'A';
      ++oddCnt;
    }
    else cnt[c] /= 2;
  }

  if (oddCnt > 1 || (oddCnt == 1 && name.size() % 2 == 0)) 
    fail();

  if (oddCnt) 
    cnt[center - 'A'] = (cnt[center - 'A'] - 1) / 2;
  for (int c = 0; c < 26; ++c){
    while (cnt[c]--) res.push_back(c + 'A');
  }
  success(oddCnt);
}

int main(){
  fastio
  input();
  solve();
  return 0;
}