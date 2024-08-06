#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 11111111111
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, K;
typedef long long ll;
vector<pair<int, int>> edges[10001];
vector<vector<ll>> distances;
typedef struct ELEMENT{
  int pos; ll dst; int cnt;
}element;
struct cmp{
  bool operator()(element &a, element &b){
    if (a.dst == b.dst) return a.cnt > b.cnt;
    return a.dst > b.dst;
  }
};
priority_queue<element, vector<element>, cmp> pq;

void input(){
  fastio
  cin >> N >> M >> K;
  int a, b, c;
  for (int i = 0; i < M; ++i){
    cin >> a >> b >> c;
    edges[a].push_back({c, b});
    edges[b].push_back({c, a});
  }
}

void dijkstra(){
  ll ans = INF;
  distances.resize(N + 1, vector<ll>(K + 1, INF));

  pq.push({1, 0, 0});
  distances[1][0] = 0;

  while (pq.size()){
    auto [cur, dst, cnt] = pq.top();
    pq.pop();

    if (distances[cur][cnt] < dst) continue;

    for (auto edge : edges[cur]){
      auto [dst, nxt] = edge;
      if (distances[nxt][cnt] > distances[cur][cnt] + dst){
        distances[nxt][cnt] = distances[cur][cnt] + dst;
        pq.push({nxt, distances[nxt][cnt], cnt});
      }
      if (cnt < K && distances[nxt][cnt + 1] > distances[cur][cnt]){
        distances[nxt][cnt + 1] = distances[cur][cnt];
        pq.push({nxt, distances[nxt][cnt + 1], cnt + 1});
      }
    }
  }

  for (int i = 0; i <= K; ++i)
    ans = min(ans, distances[N][i]);
  cout << ans;

}

void solve(){
  dijkstra();
}

int main(){
  input();
  solve();
  return 0;
}