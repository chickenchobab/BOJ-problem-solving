#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
vector<pair<int, int>> graph[40001];
int level[40001], dist[40001];
int parent[40001][16];

int lca(int a, int b){
  if (level[a] > level[b])
    swap(a, b);

  if (level[a] != level[b])
    for (int p = 15; p >= 0; --p)
      if (level[a] <= level[parent[b][p]]) // 범위 체크
        b = parent[b][p];
    
  int ret = a;
  if (a != b){
    for (int p = 15; p >= 0; --p){
      if (parent[a][p] != parent[b][p]){ // 범위 체크
        a = parent[a][p];
        b = parent[b][p];
      }
    }
    ret = parent[a][0];
  }

  return ret;
}

void processQueries(){
  int M;
  cin >> M;
  int a, b;
  while (M--){
    cin >> a >> b;
    int ancestor = lca(a, b);
    cout << dist[a] + dist[b] - 2 * dist[ancestor] << '\n';
  }
}

void dfs(int cur){
  for (auto [nxt, d] : graph[cur]){
    if (level[nxt]) continue;

    level[nxt] = level[cur] + 1;
    dist[nxt] = dist[cur] + d;

    parent[nxt][0] = cur;
    for (int p = 1; p <= 15; ++p)
      parent[nxt][p] = parent[parent[nxt][p - 1]][p - 1];

    dfs(nxt);
  }
}

void setTree(){
  level[1] = 1;
  dist[1] = 0;
  dfs(1);
}

void makeGraph(){
  cin >> N;
  int a, b, c;
  for (int e = 1; e < N; ++e){
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
}

int main(){
  fastio
  makeGraph();
  setTree();
  processQueries();
  return 0;
}