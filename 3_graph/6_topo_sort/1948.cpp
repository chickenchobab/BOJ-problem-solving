#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m, s, e;
vector<pair<int, int>> edges[10001];
int inDegree[10001];
queue<int> q;
int maxTime[10001];
vector<int> criEdges[10001];
int criEdgeCnt;
bool visited[10001];

void input(){
  fastio
  cin >> n >> m;
  int a, b, c;
  while (m--){
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    inDegree[b]++;
  }
  cin >> s >> e;
}

void findCriPath(){
  q.push(s);

  while (q.size()){
    int cur = q.front(); 
    q.pop();

    for (auto &edge : edges[cur]){
      auto [nxt, weight] = edge;

      if (maxTime[nxt] < maxTime[cur] + weight){
        maxTime[nxt] = maxTime[cur] + weight;
        criEdges[nxt].clear();
        criEdges[nxt].push_back(cur);
      }
      else if (maxTime[nxt] == maxTime[cur] + weight){
        criEdges[nxt].push_back(cur);
      }

      if(--inDegree[nxt] == 0){
        q.push(nxt);
      }
    }
  }
}

void cntCriEdges(int cur){
  
  visited[cur] = 1;
  for (int &nxt : criEdges[cur]){
    ++criEdgeCnt;
    if (!visited[nxt]) cntCriEdges(nxt);
  }
}

void solve(){
  findCriPath();
  cntCriEdges(e);
  cout << maxTime[e] << '\n' << criEdgeCnt;
}

int main(){
  input();
  solve();
  return 0;
}