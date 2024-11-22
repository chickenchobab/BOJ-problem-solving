#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ROBOT ('o')
#define DIRT ('*')
#define WALL ('x')
#define MAX (20 * 20 * 11)
using namespace std;

int w, h;
char room[20][20];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
typedef pair<int, int> p;
int status;

void input(){
  cin >> w >> h;
  if (!w && !h) exit(0);
  string str;
  for (int r = 0; r < h; ++r){
    cin >> str;
    for (int c = 0; c < w; ++c){
      room[r][c] = str[c];
    }
  }
}

void findNodes(vector<p> &nodes){
  nodes.push_back({0, 0});

  for (int r = 0; r < h; ++r){
    for (int c = 0; c < w; ++c){
      if (room[r][c] == ROBOT)
        nodes.front() = {r, c};
      else if (room[r][c] == DIRT)
        nodes.push_back({r, c});
    }
  }
}

void bfs(int r, int c, vector<vector<int>> &dist){
  queue<pair<int, int>> q;

  q.push({r, c});
  dist[r][c] = 0;

  while (q.size()){
    auto [r, c] = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d){
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
      if (dist[nr][nc] != -1) continue;
      if (room[nr][nc] == WALL) continue;
      q.push({nr, nc});
      dist[nr][nc] = dist[r][c] + 1;
    }
  }
}

void makeGraph(vector<vector<p>> &graph, vector<p> &nodes){
  graph.resize(nodes.size());
  
  for (int i = 0; i < nodes.size(); ++i){
    vector<vector<int>> dist(h, vector<int>(w, -1));

    bfs(nodes[i].first, nodes[i].second, dist);
    for (int j = i + 1; j < nodes.size(); ++j){
      int d = dist[nodes[j].first][nodes[j].second];
      if (d == -1) continue;
      graph[i].push_back({j, d});
      graph[j].push_back({i, d});
    }
  }
}

int tsp(int cur, int visited, vector<vector<int>> &dp, vector<vector<p>> &graph){
  status = max(status, visited);
  
  if (visited == (1 << graph.size()) - 1)
    return dp[cur][visited] = 0;
  if (dp[cur][visited] != -1)
    return dp[cur][visited];
  
  dp[cur][visited] = MAX;

  for (auto edge : graph[cur]){
    auto [nxt, weight] = edge;
    if (visited & (1 << nxt)) continue;
    dp[cur][visited] = min(dp[cur][visited], tsp(nxt, visited | (1 << nxt), dp, graph) + weight);
  }

  return dp[cur][visited];
}

void solve(){
  int answer;
  status = 0;
  vector<vector<p>> graph;
  vector<p> nodes;
  vector<vector<int>> dp;

  findNodes(nodes);
  makeGraph(graph, nodes);

  dp.assign(nodes.size(), vector<int>(1 << nodes.size(), -1));
  answer = tsp(0, 1, dp, graph);

  status == (1 << nodes.size()) - 1 ? cout << answer : cout << -1;
  cout << '\n';
}

int main(){
  fastio
  while (1){
    input();
    solve();
  }
  return 0;
}