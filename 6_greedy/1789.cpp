#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

long long S;

void init(){
  cin >> S;
}

void solve(){
  long long n = 0;
  while (S >= n)
    S -= n++;
  cout << n - 1;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}