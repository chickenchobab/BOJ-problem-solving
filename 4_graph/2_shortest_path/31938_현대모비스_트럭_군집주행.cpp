#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF LONG_LONG_MAX
using namespace std;

int N, M;
vector<pair<int, int>> edges[200002];
typedef long long ll;
typedef pair<int, ll> p;
struct cmp{
  bool operator()(p &a, p &b){
    return a.second > b.second;
  }
};
priority_queue<p, vector<p>, cmp> pq;
vector<ll> dist;
vector<int> finalDist;

void input(){
  fastio
  cin >> N >> M;
  int a, b, c;
  for (int i = 0; i < M; ++i){
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }
}

void dijkstra(){
  dist.assign(N + 1, INF);
  finalDist.assign(N + 1, 1111111);

  dist[1] = 0;
  pq.push({1, 0});

  while (pq.size()){
    auto [cur, dst] = pq.top();
    pq.pop();

    if (dist[cur] < dst) continue;

    for (auto &edge : edges[cur]){
      auto [nxt, dst] = edge;
      if (dist[nxt] < dist[cur] + dst) continue;

      if (dist[nxt] > dist[cur] + dst){
        finalDist[nxt] = dst;
        dist[nxt] = dist[cur] + dst;
        pq.push({nxt, dist[nxt]});
      }
      else if (finalDist[nxt] > dst){
        finalDist[nxt] = dst;
      }
    }
  }
}

void solve(){
  ll answer = 0;
  dijkstra();
  for (int i = 2; i <= N; ++i){
    answer += dist[i] * 9 / 10;
    answer += finalDist[i] * 1 / 10;
  }
  cout << answer;
}

int main(){
  input();
  solve();
  return 0;
}