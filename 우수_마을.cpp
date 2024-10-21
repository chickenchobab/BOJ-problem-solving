#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int population[10001];
vector<int> graph[10001];
// no consecutive 2 good
// at most 2 consecutive bad in internal
// if leaf bad its parent good

void input(){
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> population[i];
  int a, b;
  for (int i = 1; i < N; ++i){
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

void solve(){
  
}

int main(){
  fastio
  input();
  solve();
  return 0;
}