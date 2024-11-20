#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K;
vector<int> value(10);

void input(){
  cin >> N >> K;
  for (int i = 0; i < N; ++i)
    cin >> value[i];
}

void solve(){
  int answer = 0;
  // greedy because of the one coin
  sort(value.rbegin(), value.rend());
  for (int i = 0; i < N; ++i){
    if (K < value[i]) continue;
    answer += (K / value[i]);
    K %= value[i];
  }
  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}