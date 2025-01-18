#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, K;
vector<pair<int, int>> graph[100001];
int level[100001];
int parent[100001][17];
int minWeight[100001][17], maxWeight[100001][17];

void findMinMaxRoad(int a, int b){
  int minRoad = 1000001, maxRoad = 0;

  if (level[a] > level[b])
    swap(a, b);

  int depth = level[b] - level[a];

  for (int p = 0; depth; ++p){
    if (depth % 2){
      minRoad = min(minRoad, minWeight[b][p]);
      maxRoad = max(maxRoad, maxWeight[b][p]);
      b = parent[b][p];
    }
    depth = depth >> 1;
  }
  
  if (a != b){
    for (int p = 16; p >= 0; --p){
      if (parent[a][p] != parent[b][p]){
        minRoad = min(minRoad, min(minWeight[a][p], minWeight[b][p]));
        maxRoad = max(maxRoad, max(maxWeight[a][p], maxWeight[b][p]));
        a = parent[a][p];
        b = parent[b][p];
      }
    }
    minRoad = min(minRoad, min(minWeight[a][0], minWeight[b][0]));
    maxRoad = max(maxRoad, max(maxWeight[a][0], maxWeight[b][0]));
  }

  cout << minRoad << ' ' << maxRoad << '\n';
}

void processQueries(){
  cin >> K;
  int a, b;
  while (K--){
    cin >> a >> b;
    findMinMaxRoad(a, b);
  }
}

void dfs(int cur){
  for (auto [nxt, d] : graph[cur]){
    if (level[nxt]) continue;

    level[nxt] = level[cur] + 1;

    parent[nxt][0] = cur;
    minWeight[nxt][0] = maxWeight[nxt][0] = d;
    for (int p = 1; p < 17; ++p){
      parent[nxt][p] = parent[parent[nxt][p - 1]][p - 1];
      minWeight[nxt][p] = min(minWeight[nxt][p - 1], minWeight[parent[nxt][p - 1]][p - 1]);
      maxWeight[nxt][p] = max(maxWeight[nxt][p - 1], maxWeight[parent[nxt][p - 1]][p - 1]);
    }

    dfs(nxt);
  }
}

void traverseTree(){
  level[1] = 1;
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
  traverseTree();
  processQueries();
  return 0;
}