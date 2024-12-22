#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K, W;
int D[1001];
vector<int> graph[1001];
int inDegree[1001];
int dp[1001];

void init(){
  cin >> N >> K;
  for (int i = 1; i <= N; ++i)
    cin >> D[i];
  for (int i = 1; i <= N; ++i)
    graph[i].clear();
  fill(inDegree + 1, inDegree + N + 1, 0);
  int X, Y;
  for (int i = 1; i <= K; ++i){
    cin >> X >> Y;
    graph[X].push_back(Y);
    ++inDegree[Y];
  }
  cin >> W;
  fill(dp + 1, dp + N + 1, 0);
}

void solve(){
  queue<int> q;

  for (int i = 1; i <= N; ++i){
    if (!inDegree[i]) {
      q.push(i);
      dp[i] = D[i];
    }
  }
  
  while (!q.empty()){
    int cur = q.front();
    q.pop();

    for (int nxt : graph[cur]){
      if (--inDegree[nxt] == 0)
        q.push(nxt);
      dp[nxt] = max(dp[nxt], dp[cur] + D[nxt]);
    }
  }

  cout << dp[W] << '\n';
}

int main(){
  fastio
  int T;
  cin >> T;
  while (T--){
    init();
    solve();
  }
  return 0;
}