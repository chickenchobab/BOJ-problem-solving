#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;

void init(){
  cin >> N;
}

void solve(){
  int num;
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < N * N; ++i){
    cin >> num;
    if (pq.size() < N)
      pq.push(num);
    else if (pq.size() == N && pq.top() < num){
      pq.pop();
      pq.push(num);
    }
  }

  cout << pq.top();
}

int main(){
  fastio
  init();
  solve();
  return 0;
}