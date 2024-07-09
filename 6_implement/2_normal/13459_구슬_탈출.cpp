#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
char map[11][11];
bool visited[11][11][11][11];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef struct NODE{
  int ri, rj, bi, bj, time;
}node;
queue<node> q;
int ri, rj, bi, bj;

void input(){
  fastio
  cin >> N >> M;
  string str;
  for (int i = 1; i <= N; ++ i){
    cin >> str;
    for (int j = 1; j <= M; ++ j){
      map[i][j] = str[j - 1];
      if (map[i][j] == 'R') ri = i, rj = j;
      else if (map[i][j] == 'B') bi = i, bj = j;
    }
  }
}

void move(node f, int d){
  bool rstop, bstop;
  ri = f.ri, rj = f.rj, bi = f.bi, bj = f.bj;

  while (1){
    rstop = 0, bstop = 0;
    if (map[ri + di[d]][rj + dj[d]] == '#') rstop = 1;
    if (ri + di[d] == bi && rj + dj[d] == bj) rstop = 1;
    if (map[ri][rj] == 'O') rstop = 1;

    if (map[bi + di[d]][bj + dj[d]] == '#') bstop = 1;
    if (bi + di[d] == ri && bj + dj[d] == rj) bstop = 1;
    if (map[bi][bj] == 'O' || map[bi + di[d]][bj + dj[d]] == 'O') return;

    if (!rstop) ri += di[d], rj += dj[d];
    if (!bstop) bi += di[d], bj += dj[d];

    if (rstop && bstop){
      if (visited[ri][rj][bi][bj]) return;
      q.push({ri, rj, bi, bj, f.time + 1});
      visited[ri][rj][bi][bj] = 1;
      return;
    }
  }
}

int bfs(){
  q.push({ri, rj, bi, bj, 0});
  visited[ri][rj][bi][bj] = 1;

  while (q.size()){
    node f = q.front();
    q.pop();
    if (map[f.ri][f.rj] == 'O') 
      return 1;
    if (f.time == 10) continue;
    for (int d = 0; d < 4; ++ d){
      move(f, d);
    }
  }
  return 0;
}

void solve(){
  cout << bfs();
}

int main(){
  input();
  solve();
  return 0;
}