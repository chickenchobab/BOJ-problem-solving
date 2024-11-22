#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int price[15][15];
int dp[15][1 << 15][10];

void init(){
  cin >> N;
  char ch;
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      cin >> ch;
      price[i][j] = ch - '0';
    }
  }
  memset(dp, -1, sizeof(dp));
}

int dfs(int cur, int state, int purchase){
  if (state == (1 << N) - 1)
    return (dp[cur][state][purchase] = 0) + 1;

  if (dp[cur][state][purchase] != -1)
    return dp[cur][state][purchase];

  dp[cur][state][purchase] = 0;

  for (int nxt = 0; nxt < N; ++nxt){
    if (state & (1 << nxt)) continue;
    if (price[cur][nxt] < purchase) continue;

    dp[cur][state][purchase] = max(dp[cur][state][purchase], dfs(nxt, state | (1 << nxt), price[cur][nxt]));
  }

  return dp[cur][state][purchase] + 1;
}

void solve(){
  cout << dfs(0, 1, 0);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}