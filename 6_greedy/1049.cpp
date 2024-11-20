#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int minEach, minPack;

void input(){
  fastio
  cin >> N >> M;
}

void solve(){
  int answer = 0;
  int a, b;

  minEach = minPack = 1000;
  while (M--){
    cin >> a >> b;
    minPack = min(a, minPack);
    minEach = min(b, minEach);
  }

  if (minPack < minEach * 6){
    answer += (N / 6) * minPack;
    answer += min(minPack, (N % 6) * minEach);
  }
  else {
    answer += N * minEach;
  }

  cout << answer;
}

int main(){
  input();
  solve();
  return 0;
}