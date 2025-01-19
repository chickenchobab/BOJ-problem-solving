#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int V, E;
vector<int> graph[10001];
stack<int> s;
int idx;
int visited[10001];
bool extracted[10001];
vector<vector<int>> vecScc;

void printAnswer(){
  for (auto &scc : vecScc)
    sort(begin(scc), end(scc));

  sort(begin(vecScc), end(vecScc), [](vector<int> &a, vector<int> &b){
    return a.front() < b.front();
  });

  cout << vecScc.size() << '\n';
  for (auto &scc : vecScc){
    for (auto node : scc)
      cout << node << ' ';
    cout << "-1\n";
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
    vector<int> scc;
    int node = 0;

    do {
      node = s.top();
      s.pop();
      scc.push_back(node);
      extracted[node] = 1;
    }while (node != cur);

    vecScc.push_back(scc);
  }

  return parent;
}

void findScc(){
  for (int start = 1; start <= V; ++start)
    if (!visited[start])
      dfs(start);
}

void makeGraph(){
  cin >> V >> E;
  int a, b;
  for (int e = 0; e < E; ++e){
    cin >> a >> b;
    graph[a].push_back(b);
  }
}

int main(){
  fastio
  makeGraph();
  findScc();
  printAnswer();
  return 0;
}