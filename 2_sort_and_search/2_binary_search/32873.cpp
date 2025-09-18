#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;

void init(){
  cin >> N;
}

void solve(){
  int a;
  vector<int> tops;

  cin >> a;
  tops.push_back(a);

  for (int i = 2; i <= N; ++i){
    cin >> a;
    if (a > tops.back())
      tops.push_back(a);
    else {
      int pos = lower_bound(begin(tops), end(tops), a) - begin(tops);
      tops[pos] = a;
    }
  }

  cout << tops.size();
}

int main(){
  fastio
  init();
  solve();
  return 0;
}