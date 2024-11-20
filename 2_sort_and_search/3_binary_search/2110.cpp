#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000000000
using namespace std;

int N, C;
vector<int> houses;

void input(){
  cin >> N >> C;
  houses.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> houses[i];
}

bool isPossible(int minGap){

  int actualMinGap = minGap;
  int numRouter = 1;
  int house = houses[0];

  for (int h = 1; h < N && numRouter < C; ++h){
    int gap = houses[h] - house;
    if (gap < minGap) continue;
    
    ++numRouter;
    house = houses[h];
  }
  
  return (numRouter == C);
}

void solve(){
  sort(houses.begin(), houses.end());

  int answer = 0;
  int s = 1, e = houses.back() - houses.front();

  while (s <= e){
    int m = (s + e) / 2;
    if (isPossible(m)){
      s = m + 1;
      answer = m;
    }
    else e = m - 1;
  }

  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}