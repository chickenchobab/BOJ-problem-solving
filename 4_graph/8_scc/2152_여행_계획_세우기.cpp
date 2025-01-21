#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using edge = pair<int, int>;

int N, M, S, T;
vector<int> graph[10001];
int idx;
stack<int> s;
int visited[10001], extracted[10001];
vector<int> cycleSize;
vector<int> cycleGraph[10001];

int dijkstra(){
  vector<int> dist(cycleSize.size(), 0);
  priority_queue<edge, vector<edge>, less<edge>> pq;

  dist[extracted[S]] = cycleSize[extracted[S]];
  pq.push({dist[extracted[S]], extracted[S]});

  while (!pq.empty()){
    auto [d, cur] = pq.top();
    pq.pop();

    if (dist[cur] > d) continue;

    for (int nxt : cycleGraph[cur]){
      if (dist[nxt] < dist[cur] + cycleSize[nxt]){
        dist[nxt] = dist[cur] + cycleSize[nxt];
        pq.push({dist[nxt], nxt});
      }
    }
  }
  
  return dist[extracted[T]];
}

void makeCycleGraph(){
  for (int i = 1; i <= N; ++i){
    for (int j : graph[i]){
      if (extracted[i] == extracted[j])
        continue;
      cycleGraph[extracted[i]].push_back(extracted[j]);
    }
  }
}

int dfs(int cur){
  int parent = visited[cur] = ++idx;
  s.push(cur);

  for (int nxt : graph[cur]){
    if (!visited[nxt])
      parent = min(parent, dfs(nxt));
    else if (!extracted[nxt])
      parent = min(parent, visited[nxt]);
  }

  if (parent == visited[cur]){
    int cnt = 0;
    int node;
    do {
      node = s.top();
      s.pop();
      extracted[node] = cycleSize.size();
      ++cnt;
    } while (node != cur);

    cycleSize.push_back(cnt);
  }

  return parent;
}

void findScc(){
  for (int start = 1; start <= N; ++start)
    if (!visited[start])
      dfs(start);
}

void init(){
  cin >> N >> M >> S >> T;
  int A, B;
  while (M--){
    cin >> A >> B;
    graph[A].push_back(B);
  }
  cycleSize.push_back(0);
}

int main(){
  fastio
  init();
  findScc();
  makeCycleGraph();
  cout << dijkstra();
  return 0;
}