#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF LONG_LONG_MAX

using namespace std;

int N, M;
typedef long long ll;
typedef pair<int, ll> p;
vector<p> edges[200002], tree[200002];
vector<ll> costs;
int parent[200002], inherit[200002], children[200002];
struct cmp{
  bool operator()(p &a, p &b){
    return a.second > b.second;
  }
};
// priority_queue<p, vector<p>, cmp> pq;
queue<p> q;
ll totalCost;

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
  costs.resize(N + 1, INF);

  q.push({1, 0});
  costs[1] = 0;

  while (!q.empty()){
    auto [cur, cost] = q.front();
    q.pop();

    // if (costs[cur] < cost) continue;

    for (auto &e : edges[cur]){
      auto [nxt, cost] = e;
      if (costs[nxt] > costs[cur] + cost){
        costs[nxt] = costs[cur] + cost;
        q.push({nxt, costs[nxt]});
        parent[nxt] = cur;
        inherit[nxt] = cost;
      }
    }
  }
}

int cntChildren(int cur){
  int ret = 0;
  for (auto &e : tree[cur]){
    auto [nxt, cost] = e;
    ret += cntChildren(nxt);
  }
  children[cur] = ret;
  return ret + 1;
}

void platoon(int cur, int cnt){
  
  if (--cnt == 0) return;
  int siz = tree[cur].size();
  if (!siz) return;

  for (int i = 0; i < siz - 1; ++i){
    auto [nxt, cost] = tree[cur][i];
    totalCost += (cost * children[nxt] * 9 / 10 + cost);
    // cout << cur << " to " << nxt << ": " << (children[nxt] + 1) << ' ' << ((9 * children[nxt] / 10 + 1) * cost) << endl;
    // cout << 9 * children[nxt] / 10 * cost << ' ' << cost << endl;
    cnt -= (children[nxt] + 1);
    platoon(nxt, children[nxt] + 1);
  }
  auto [nxt, cost] = tree[cur][siz - 1];
  totalCost += (cost * max(0, cnt - 1) * 9 / 10 + cost);
  // cout << cur << " to " << nxt << ": " << (children[nxt] + 1) << ' ' << ((9 * children[nxt] / 10 + 1) * cost) << endl;
  // cout << 9 * children[nxt] / 10 * cost << ' ' << cost << endl;
  platoon(nxt, cnt);
}

void solve(){
  for (int i = 1; i <= N; ++i){
    sort(edges[i].begin(), edges[i].end(),
    [](p &a, p &b){
      return a.second > b.second;
    });
  }
  dijkstra();
  for (int i = 1; i <= N; ++i){
    tree[parent[i]].push_back({i, inherit[i]});
  }
  cntChildren(1);
  for (int i = 1; i <= N; ++i){
    sort(tree[i].begin(), tree[i].end(),
    [](p &a, p &b){
      return a.second < b.second;
    });
  }
  platoon(1, N);

  // for (int i = 1; i <= N; ++i){
  //   cout << parent[i] << ' ';
  // }
  // cout << endl;
  // for (int i = 1; i <= N; ++i){
  //   cout << children[i] << ' ';
  // }
  // cout << endl;
  cout << totalCost;
}

int main(){
  input();
  solve();
  return 0;
}