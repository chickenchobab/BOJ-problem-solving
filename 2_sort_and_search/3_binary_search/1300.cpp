#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

int N;
int k;

void init(){
  cin >> N >> k;
}

ll cntLessEqual(ll num){
  ll ret = 0;
  for (int i = 1; i <= N; ++i)
    ret += min(num / i, (ll)N);
  return ret;
}

void solve(){
  ll answer;
  ll s = 1, e = (ll)N * (ll)N;

  while (s <= e){
    ll m = (s + e) / 2;
    ll numLessEqual = cntLessEqual(m);

    if (numLessEqual < k)
      s = m + 1;
    else {
      answer = m;
      e = m - 1;
    }
  }

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}