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
  
  for (int i = 0; ; ++i){
    N -= i;
    if (N <= 0) break;
    answer += !(N % (i + 1));
  }
  
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}