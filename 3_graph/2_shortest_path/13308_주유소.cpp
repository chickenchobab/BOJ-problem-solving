#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 15625000000
using namespace std;

int N, M;
int price[2501];
typedef long long ll;
vector<pair<int, int>> edges[2501];
typedef struct ELEMENT{
  int pos; ll dst; int source; // recent oil source
}element;
struct cmp{
  bool operator()(element &a, element &b){
    if (a.dst == b.dst) return price[a.source] > price[b.source];
    return a.dst > b.dst;
  }
};
priority_queue<element, vector<element>, cmp> pq;
vector<vector<ll>> distances;

void input(){
  fastio
  cin >> N >> M;
  for (int i = 1; i <= N; ++i)
    cin >> price[i];
  int a, b, c;
  for (int i = 1; i <= M; ++i){
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }
}

ll getMinCost(){
  distances.assign(2501, vector<ll>(2501, INF));
  
  // distances[1][price[1]] = 0;
  pq.push({1, 0, 1});

  while (pq.size()){
    auto [cur, curDist, curSource] = pq.top();
    pq.pop();

    if (distances[cur][price[curSource]] != INF) continue;
    distances[cur][price[curSource]] = curDist;
    if (cur == N) return curDist;

    for (auto &edge : edges[cur]){
      auto [nxt, nxtDist] = edge;
      int nxtSource = price[curSource] < price[nxt] ? curSource : nxt;

      if (distances[nxt][price[nxtSource]] == INF){
        // distances[nxt][price[nxtSource]] = distances[cur][price[curSource]] + price[curSource] * nxtDist;
        pq.push({nxt, distances[cur][price[curSource]] + price[curSource] * nxtDist, nxtSource});
      }
    }
  }

  return INF;
}

void solve(){
  typedef pair<int, int> p;
  for (int i = 1; i <= N; ++i)
    sort(edges[i].begin(), edges[i].end(), [](p &a, p& b){
      if (a.second == b.second) return price[a.first] < price[b.first];
      return a.second < b.second;
    });
  cout << getMinCost();
}

int main(){
  input();
  solve();
  return 0;
}