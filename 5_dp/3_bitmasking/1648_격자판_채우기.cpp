#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DIVISOR 9901

using namespace std;
using ll = long long;

int N, M;
int dp[14][14][1 << 14];
int mask;

int dfs(int r, int c, bool isFilled, int state){
  if (c == M) ++r, c = 0;
  if (r == N) return 1;

  if (dp[r][c][state] != -1)
    return dp[r][c][state];

  if (isFilled)
    return dp[r][c][state] = dfs(r, c + 1, state & 1, state >> 1 & mask);
  
  ll ret = 0;
  if (c < M - 1 && !(state & 1))
    ret = (ret + dfs(r, c + 1, 1, state >> 1 & mask)) % DIVISOR;
  if (r < N - 1 && !(state & (1 << (M - 1))))
    ret = (ret + dfs(r, c + 1, (state & 1) || (1 << (M - 1) & 1), (state >> 1 | (1 << (M - 2))) & mask)) % DIVISOR;
  return dp[r][c][state] = ret;
}

void solve(){
  mask = (1 << M) - 1;
  cout << dfs(0, 0, 0, 0);
}

void init(){
  cin >> N >> M;
  fill(&dp[0][0][0], &dp[13][13][(1 << 14) - 1] + 1, -1);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}