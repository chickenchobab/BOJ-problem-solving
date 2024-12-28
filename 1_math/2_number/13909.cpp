#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;

void init(){
  cin >> N;
}

void solve(){
  cout << (int)sqrt(N);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}