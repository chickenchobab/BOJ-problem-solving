#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K;
int civilCnt;
deque<pair<int, int>> civilized;
bool visited[2001][2001];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int parent[2000 * 2000 + 1];

void input(){
  fastio
  cin >> N >> K;
  int x, y;
  while (K--){
    cin >> x >> y;
    ++civilCnt;
    visited[x][y] = 1;
    civilized.push_back({x, y});
  }
}

int find(int x){
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);

  if (a == b) return;

  if (parent[a] < parent[b]) {
    parent[a] += parent[b];
    parent[b] = a;
  }
  else {
    parent[b] += parent[a];
    parent[a] = b;
  }
}

void solve(){
  int M = N * N;
  for (int c = 1; c <= M; ++c)
    parent[c] = -1;

  int time = 0;
  auto [i, j] = civilized.front();
  int firstCivil = (i - 1) * N + j;

  while (!civilized.empty()){

    int cnt = civilized.size();
    for (int c = 0; c < cnt; ++c) {
      auto [i, j] = civilized[c];
      for (int d = 0; d < 4; ++d){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
        if (visited[ni][nj]) 
          merge((i - 1) * N + j, (ni - 1) * N + nj);
      }
    }

    if (parent[find(firstCivil)] == -civilCnt) break;
    ++time;

    while (cnt--){
      auto [i, j] = civilized.front();
      civilized.pop_front();
      for (int d = 0; d < 4; ++d){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
        if (visited[ni][nj]) continue;
        ++civilCnt;
        visited[ni][nj] = 1;
        civilized.push_back({ni, nj});
      }
    }
  }
  cout << time;
}

int main(){
  input();
  solve();
  return 0;
}