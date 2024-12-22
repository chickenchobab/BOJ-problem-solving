#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
int N;
vector<int> cards;
vector<vector<int>> dp;

void init(){
  cin >> N;
  cards.resize(N);
  dp.assign(N, vector<int>(N, 0));
  for (int i = 0; i < N; ++i)
    cin >> cards[i];
}

int makeBestMove(int turn, int s, int e){
  if (turn > N)
    return 0;

  if (dp[s][e]) 
    return dp[s][e];

  if (turn % 2)
    dp[s][e] = max(cards[s] + makeBestMove(turn + 1, s + 1, e), cards[e] + makeBestMove(turn + 1, s, e - 1));
  else 
    dp[s][e] = min(makeBestMove(turn + 1, s + 1, e), makeBestMove(turn + 1, s, e - 1));
  
  return dp[s][e];
}

void solve(){
  cout << makeBestMove(1, 0, N - 1) << '\n';
}

int main(){
  fastio
  cin >> T;
  while (T--){
    init();
    solve();
  }
  return 0;
}