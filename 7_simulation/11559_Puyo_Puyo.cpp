#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define UNCHECKED 0
#define CHECKED 1
#define MARKED 2
using namespace std;

char field[12][6];
vector<vector<int>> status;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

void input(){
  for (int r = 0; r < 12; ++r){
    for (int c = 0; c < 6; ++c){
      cin >> field[r][c];
    }
  }
}

void showField(){
  for (int r = 0; r < 12; ++r){
    for (int c = 0; c < 6; ++c){
      cout << field[r][c] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

void calcGroupSize(int r, int c, vector<pair<int, int>> &puyos){
  queue<pair<int, int>> q;

  status[r][c] = CHECKED;
  q.push({r, c});
  puyos.push_back({r, c});

  while (q.size()){
    auto [r, c] = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir){
      int nr = r + dr[dir];
      int nc = c + dc[dir];
      if (nc < 0 || nc >= 6 || nr < 0 || nr >= 12) continue;
      if (status[nr][nc]) continue;
      if (field[nr][nc] != field[r][c]) continue;
      status[nr][nc] = CHECKED;
      q.push({nr, nc});
      puyos.push_back({nr, nc});
    }
  }
}

void markPuyos(vector<pair<int, int>> &puyos){
  for (auto p : puyos){
    status[p.first][p.second] = MARKED;
  }
}

void explodePuyos(){
  for (int c = 0; c < 6; ++c){
    int fall = 0;
    for (int r = 11; r >= 0; --r){
      if (field[r][c] == '.') break;
      if (status[r][c] == MARKED){
        ++fall;
        field[r][c] = '.';
      }
      else if (fall){
        field[r + fall][c] = field[r][c];
        field[r][c] = '.';
      }
    }
  }
}

bool checkField(){
  bool ret = 0;
  status.assign(12, vector<int>(6, 0));

  for (int c = 0; c < 6; ++c){
    for (int r = 11; r >= 0; --r){
      if (field[r][c] == '.') break;
      if (status[r][c]) continue;
      
      vector<pair<int, int>> puyos;
      calcGroupSize(r, c, puyos);
      // cout << puyos.size() << ' ';
      if (puyos.size() >= 4){
        markPuyos(puyos);
        ret = 1;
      }
    }
  }
  return ret;
}

void solve(){
  int answer = 0;
  while (checkField()){
    // showField();
    explodePuyos();
    ++answer;
  }
  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}