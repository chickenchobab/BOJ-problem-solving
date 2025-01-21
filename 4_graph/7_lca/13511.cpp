#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int N, M;
vector<pair<int, int>> graph[100001];
int level[100001];
ll cost[100001];
int parent[100001][17];

int lca(int u, int v){
  if (level[u] > level[v])
    swap(u, v);
  
  if (level[u] != level[v])
    for (int p = 16; p >= 0; --p)
      if (level[u] <= level[parent[v][p]])
        v = parent[v][p];

  int ret = u;

  if (u != v){
    for (int p = 16; p >= 0; --p){
      if (parent[u][p] != parent[v][p]){
        u = parent[u][p];
        v = parent[v][p];
      }
    }
    ret = parent[u][0];
  }

  return ret;
}

int findNode(int u, int v, int k){
  int root = lca(u, v);
  --k;

  int a = min(k, level[u] - level[root]);
  k -= a;
  for (int p = 0; a; ++p){
    if (a % 2)
      u = parent[u][p];
    a = a >> 1;
  }

  if (!k)
    return u;

  int b = level[v] - level[root] - k;
  for (int p = 0; b; ++p){
    if (b % 2)
      v = parent[v][p];
    b = b >> 1;
  }

  return v;
}

void processQueries(){
  cin >> M;
  int command, u, v, k;

  while (M--){
    cin >> command;
    if (command == 1){
      cin >> u >> v;
      cout << cost[u] + cost[v] - 2 * cost[lca(u, v)];
    }
    else {
      cin >> u >> v >> k;
      cout << findNode(u, v, k);
    }
    cout << '\n';
  }
}

void dfs(int cur){
  for (auto [nxt, w] : graph[cur]){
    if (level[nxt]) continue;

    level[nxt] = level[cur] + 1;
    cost[nxt] = cost[cur] + w;

    parent[nxt][0] = cur;
    for (int p = 1; p < 17; ++p)
      parent[nxt][p] = parent[parent[nxt][p - 1]][p - 1];

    dfs(nxt);
  }
}

void traverseTree(){
  level[1] = 1;
  cost[1] = 0;
  dfs(1);
}

void init(){
  cin >> N;
  int u, v, w;
  for (int e = 1; e < N; ++e){
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
}

int main(){
  fastio
  init();
  traverseTree();
  processQueries();
  return 0;
}