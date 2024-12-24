#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

ll d;

void init(){
  ll x, y;
  cin >> x >> y;
  d = y - x;
}

ll getAnswer(){
  ll v = 1;
  ll ret = 1;
  --d;
  while (d > 0){
    if (d >= (v + 1) * (v + 2) / 2)
      ++v;
    else if (d < v * (v + 1) / 2)
      --v;
    d -= v;
    ++ret;
  }
  return ret;
}

void solve(){
  ll r = sqrt(d);
  if (r * r == d)
    cout << 2 * r - 1;
  else if (r * r < d  && d <= r * r + r)
    cout << 2 * r;
  else
    cout << 2 * r + 1;
  // cout << getAnswer();
  cout << '\n';
}

int main(){
  fastio
  int T;
  cin >> T;
  while (T--){
    init();
    solve();
  }
  return 0;
}