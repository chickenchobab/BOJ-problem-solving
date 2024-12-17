#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

long long N;

void init(){
  cin >> N;
}

void solve(){
  N % 2 ? cout << "SK" : cout << "CY";
}

int main(){
  fastio
  init();
  solve();
  return 0;
}