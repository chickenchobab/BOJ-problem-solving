#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
vector<int> graph[1000001];
int dp[1000001][2];

void init(){
  cin >> N;
  int u, v;
  for (int i = 1; i < N; ++i){
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
}

void dfs(int cur, int prv){
  dp[cur][1] = 1;

  for (int nxt : graph[cur]){
    if (nxt == prv) continue;
    dfs(nxt, cur);
    dp[cur][0] += dp[nxt][1];
    dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
  }
}

void solve(){
  dfs(1, 0);
  cout << min(dp[1][0], dp[1][1]);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}