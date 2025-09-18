#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int sum[10001];

void init(){
  cin >> N >> M;
  int num;
  for (int i = 1; i <= N; ++i){
    cin >> num;
    sum[i] = sum[i - 1] + num;
  }
}

void solve(){
  int answer = 0;
  int s = 1, e = 1;
  for (; e <= N; ++e){
    while (s <= e && sum[e] - sum[s - 1] > M)
      ++s;
    answer += (sum[e] - sum[s - 1] == M);
  }
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}