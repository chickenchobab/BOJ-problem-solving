#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int weight[100001];

void input(){
  cin >> N;
  for (int i = 1; i < N; ++i)
    cin >> weight[i];
}

void solve(){
  long long answer = 0;
  int price, minPrice = 1111111111;

  for (int i = 1; i <= N; ++i){
    cin >> price;
    minPrice = min(minPrice, price);
    answer += (long long)weight[i] * minPrice;
  }
  
  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}