#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

int N, M;
int numSumWithMod[1001];

void solve(){
  // count the multiples of M
  ll answer = numSumWithMod[0];
  // count the prefix sums with same mod
  for (int m = 0; m < M; ++m)
    answer += (ll)1 * numSumWithMod[m] * (numSumWithMod[m] - 1) / 2;
  cout << answer;
}

void init(){
  cin >> N >> M;
  int num;
  ll sum = 0;
  for (int i = 1; i <= N; ++i){
    cin >> num;
    sum += num;
    ++numSumWithMod[sum % M];
  }
}

int main(){
  fastio
  init();
  solve();
  return 0;
}