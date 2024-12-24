#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

int N;
ll x[10000], y[10000];

void init(){
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> x[i] >> y[i];
}

void solve(){
  ll answer = x[N - 1] * y[0] - x[0] * y[N - 1];

  for (int i = 0; i < N - 1; ++i){
    answer += x[i] * y[i + 1];
    answer -= x[i + 1] * y[i];
  }

  answer = abs(answer);

  if (answer % 2)
    cout << answer / 2 << ".5";
  else
    cout << answer / 2 << ".0";
}

int main(){
  fastio
  init();
  solve();
  return 0;
}