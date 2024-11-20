#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int cnt[10001];

void init(){
  cin >> N;
  int num;
  for (int i = 0; i < N; ++i){
    cin >> num;
    ++cnt[num];
  }
}

void solve(){
  for (int num = 1; num <= 10000; ++num){
    while (cnt[num]--)
      cout << num << '\n';
  }
}

int main(){
  fastio
  init();
  solve();
  return 0;
}