#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 1111111
using namespace std;

int T, N, M, K;
typedef struct ELEMENT{
  int pos, time, cost;
}element;
struct cmp{
  bool operator()(element &a, element &b){
    if (a.time == b.time) return a.cost > b.cost;
    return a.time > b.time;
  }
};
vector<element> edges[101];
priority_queue<element, vector<element>, cmp> pq;
vector<vector<int>> times;

void input(){
  cin >> N >> M >> K;
  int u, v, cost, time;
  while (K--){
    cin >> u >> v >> cost >> time;
    edges[u].push_back({v, time, cost});
  }
}

void reset(){
  for (int i = 1; i <= N; ++i)
    edges[i].clear();
}

void dijkstra(){
  times.assign(N + 1, vector<int>(M + 1, INF));

  times[1][0] = 0;
  pq.push({1, 0, 0});

  while (pq.size()){ 
    auto [cur, curTime, curCost] = pq.top();
    pq.pop();
    
    if (times[cur][curCost] < curTime) continue;

    for (auto &edge : edges[cur]){
      auto [nxt, nxtTime, nxtCost] = edge;
      int cost = curCost + nxtCost;
      int time = curTime + nxtTime;
      if (cost > M) continue;
      if (times[nxt][cost] <= time) continue;

      for (int c = cost; c <= M && times[nxt][c] > time; ++c){
        times[nxt][c] = time;
      }
      pq.push({nxt, time, cost});
    }
  }
}

void solve(){
  for (int i = 1; i <= N; ++i){
    sort(edges[i].begin(), edges[i].end(), [](element &a, element &b){
      if (a.time == b.time) return a.cost < b.cost;
      return a.time < b.time;
    });
  }
  dijkstra();
  int answer = INF;
  for (int i = 0; i <= M; ++i){
    answer = min(answer, times[N][i]);
  }
  answer == INF ? cout << "Poor KCM" : cout << answer;
  cout << '\n';
}

int main(){
  fastio
  cin >> T;
  while (T--){
    input();
    solve();
    reset();
  }
  return 0;
}