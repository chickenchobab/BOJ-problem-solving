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
  int answer = 0;
  int sum = 0;
  
  int s, e;
  s = 1;
  for (e = 1; e <= N; ++e){
    sum += e;
    while (s < e && sum > N){
      sum -= s;
      ++s;
    }
    answer += (s <= e && sum == N);
  }
  
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}