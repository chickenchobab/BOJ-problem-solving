#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K;
int arr[101];

void input(){
  fastio
  cin >> N >> K;
}

void solve(){
  for (int i = 1; i <= K; ++ i){
    cin >> arr[i];
  }
}

int main(){
  input();
  solve();
  return 0;
}