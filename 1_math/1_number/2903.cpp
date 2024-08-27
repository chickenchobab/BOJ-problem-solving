#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int N;

void input(){
  cin >> N;
}

void solve(){
  long long root = 1 + (long long)pow(2, N);
  cout << root * root;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}