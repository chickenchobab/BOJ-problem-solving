#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> graph[100001];
int inDegree[100001];
int idx;
int visited[100001];
bool extracted[100001];
stack<int> s;
int answer;

int dfs(int cur){
  int parent = visited[cur] = ++idx;
  s.push(cur);

  for (int nxt : graph[cur]){
    if (!visited[nxt]){
      --inDegree[nxt];
      parent = min(parent, dfs(nxt));
    }
    else if (!extracted[nxt]){
      --inDegree[nxt];
      parent = min(parent, visited[nxt]);
    }
  }

  if (parent == visited[cur]){
    int node;
    bool isRoot = 1;
    do {
      node = s.top();
      s.pop(); 
      extracted[node] = 1;
      if (inDegree[node])
        isRoot = 0;
    }while (node != cur);

    answer += (isRoot && s.empty());
  }

  return parent;
}

void findRootScc(){
  for (int start = 1; start <= N; ++start)
    if (!visited[start])
      dfs(start);
}

void init(){
  cin >> N >> M;
  answer = 0;
  for (int i = 1; i <= N; ++i){
    graph[i].clear();
    inDegree[i] = visited[i] = extracted[i] = 0;
  }
  int a, b;
  while (M--){
    cin >> a >> b;
    graph[a].push_back(b);
    ++inDegree[b];
  }
}

int main(){
  fastio
  int T;
  cin >> T;
  while (T--){
    init();
    findRootScc();
    cout << answer << '\n';
  }
  return 0;
}