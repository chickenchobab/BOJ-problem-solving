#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;

void input(){
  cin >> N;  
}

int getMaxCommonFactor(int a, int b){
  int lim = min(a, b);
  for (int i = lim; i >= 1; --i){
    if (a % i || b % i) continue;
    return i;
  }
}

void solve(){
  int prv, cur;
  int head, tail, commonFactor;

  cin >> head;
  cin >> cur;
  commonFactor = cur - head;
  prv = cur; 
  
  for (int i = 3; i < N; ++i){
    cin >> cur;
    commonFactor = getMaxCommonFactor(commonFactor, cur - prv);
    prv = cur;
  }

  cin >> tail;
  commonFactor = getMaxCommonFactor(commonFactor, tail - prv);

  cout << (tail - head) / commonFactor + 1 - N;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}