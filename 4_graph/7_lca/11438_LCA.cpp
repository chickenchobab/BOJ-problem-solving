#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> graph[100001];
int level[100001];
int parent[100001][17];

int lca(int a, int b){
  if (level[a] > level[b])
    swap(a, b);
  
  if (level[a] != level[b])
    for (int p = 16; p >= 0; --p)
      if (level[a] <= level[parent[b][p]]) // 지수 범위 체크
        b = parent[b][p];

  int ret = a;
  
  if (a != b){
    for (int p = 16; p >= 0; --p){
      if (parent[a][p] != parent[b][p]){ // 지수 범위 체크
        a = parent[a][p];
        b = parent[b][p];
      }
    }
    ret = parent[a][0];
  }
  
  return ret;
} 

void processQueries(){
  cin >> M;
  int a, b;
  while (M--){
    cin >> a >> b;
    cout << lca(a, b) << '\n';
  }
}

void dfs(int cur){
  for (int nxt : graph[cur]){
    if (level[nxt]) continue;

    level[nxt] = level[cur] + 1;
     
    parent[nxt][0] = cur;
    for (int p = 1; p <= 16; ++p)
      parent[nxt][p] = parent[parent[nxt][p - 1]][p - 1];

    dfs(nxt);
  }
}

void makeGraph(){
  cin >> N;
  int a, b;
  for (int e = 1; e < N; ++e){
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

void traverseTree(){
  level[1] = 1;
  dfs(1);
}

int main(){
  fastio
  makeGraph();
  traverseTree();
  processQueries();
  return 0;
}