#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

int n;
ll w;
int s[15];

void init(){
  cin >> n >> w;
  for (int i = 1; i <= n; ++i)
    cin >> s[i];
}

void solve(){
  ll numCoin = 0;

  for (int i = 1; i < n; ++i){
    if (s[i] < s[i + 1]){
      numCoin += w / s[i];
      w %= s[i];
    }
    else {
      w += numCoin * s[i];
      numCoin = 0;
    }
  }

  cout << w + numCoin * s[n];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}