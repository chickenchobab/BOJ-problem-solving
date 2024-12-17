#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

ll n;

void init(){
  cin >> n;
}

void solve(){
  int answer = 1;
  ll w = 4;
  while (n > w * answer + w - 1){
    ++answer;
    w *= 2;
  }
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}