#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 2222222

using namespace std;
using coord = pair<int, int>;

int N, W;
coord pos[1001];
// dp[i][j] : 1번은 i번 현장에 있고 2번은 j번 현장에 있을 때부터의 정답
int dp[1001][1001];
bool call[1001][1001];

int dist(coord &a, coord &b){
  return abs(a.first - b.first) + abs(a.second - b.second); 
}

void solve(){
  coord pos1, pos2;

  for (int i = W - 1; i >= 0; --i){
    pos1 = i ? pos[i] : make_pair(1, 1);

    for (int j = W - 1; j >= 0; --j){
      if (j && i == j) continue;

      pos2 = j ? pos[j] : make_pair(N, N);

      // 다음 사건 번호
      int k = max(i, j) + 1;
      // 현 시점에서 1이 출동
      int dp1 = dp[k][j] + dist(pos1, pos[k]);
      // 현 시점에서 2가 출동
      int dp2 = dp[i][k] + dist(pos2, pos[k]);

      if (dp1 < dp2){
        dp[i][j] = dp1;
        call[i][j] = 0;
      }
      else {
        dp[i][j] = dp2;
        call[i][j] = 1;
      }
    }
  } 

  cout << dp[0][0] << '\n';
  
  int i = 0, j = 0, k = 1;
  while (i < W && j < W){
    if (!call[i][j]){
      i = k++;
      cout << "1\n";
    }
    else {
      j = k++;
      cout << "2\n";
    }
  }
}

void init(){
  cin >> N >> W;
  int r, c;
  for (int i = 1; i <= W; ++i){
    cin >> r >> c;
    pos[i] = {r, c};
  }
}

int main(){
  fastio
  init();
  solve();
  return 0;
}