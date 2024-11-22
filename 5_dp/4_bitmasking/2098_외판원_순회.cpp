#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int graph[16][16];
int dp[16][1 << 16];

void init(){
  cin >> N;
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      cin >> graph[i][j];
      if (!graph[i][j]) 
        graph[i][j] = 1e9;
    }
  }
}

int tsp(int cur, int state){
  if (state == (1 << N) - 1)
    return dp[cur][state] = graph[cur][0];
  
  if (dp[cur][state]) 
    return dp[cur][state];

  dp[cur][state] = 1e9;
  
  for (int nxt = 0; nxt < N; ++nxt){
    if (graph[cur][nxt] == 1e9) continue;
    if (state & (1 << nxt)) continue;

    dp[cur][state] = min(dp[cur][state], tsp(nxt, state | (1 << nxt)) + graph[cur][nxt]);
  }

  return dp[cur][state];
}

void solve(){
  // Find cycle -> any start point.
  cout << tsp(0, 1);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}