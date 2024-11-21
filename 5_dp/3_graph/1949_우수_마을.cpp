#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int population[10001];
vector<int> graph[10001];
int dp[10001][2];

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

void selectVillage(int cur, int prv){ 
 
  dp[cur][1] = population[cur];

  for (int nxt : graph[cur]){
    if (nxt == prv) continue;
    selectVillage(nxt, cur);
    dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
    dp[cur][1] += dp[nxt][0];
  }
}

void solve(){
  int root = 1;
  selectVillage(root, 0);
  cout << max(dp[root][0], dp[root][1]);
}

int main(){
  fastio
  input();
  solve();
  return 0;
}