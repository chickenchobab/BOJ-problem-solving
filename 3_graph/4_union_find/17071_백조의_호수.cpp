#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int R, C;
char map[1500][1500];
typedef pair<int, int> pr;
deque<pr> waters;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<int> swans;
int parent[1500 * 1500];

void input(){
  fastio
  cin >> R >> C;
  string str;
  for (int i = 0; i < R; ++i){
    cin >> str;
    for (int j = 0; j < C; ++j){
      map[i][j] = str[j];
      if (map[i][j] == 'L')
        swans.push_back(i * C + j);
      if (map[i][j] != 'X'){
        waters.push_back({i, j});
        map[i][j] = 'O';
      }
    }
  }
}

void init(){
  int idx;
  for (int i = 0; i < R; ++i){
    for (int j = 0; j < C; ++j){
      idx = i * C + j;
      parent[idx] = idx;
    }
  }
}

int findParent(int x){
  if (parent[x] == x) return x;
  return parent[x] = findParent(parent[x]);
}

void unite(int a, int b){
  a = findParent(a);
  b = findParent(b);

  if (a == b) return;

  if (a < b) parent[b] = a;
  else parent[a] = b;
}

void checkWater(){

  for (auto &water : waters){
    int i = water.first;
    int j = water.second;
    for (int d = 0; d < 4; ++d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
      if (map[ni][nj] != 'O') continue;
      unite(i * C + j, ni * C + nj);
    }
  }
}

void meltIce(){
  int waterCnt = waters.size();

  while (waterCnt--){
    auto water = waters.front();
    waters.pop_front();

    int i = water.first;
    int j = water.second;
    for (int d = 0; d < 4; ++d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
      if (map[ni][nj] == 'O') continue;
      map[ni][nj] = 'O';
      waters.push_back({ni, nj});
    }
  }
}

void solve(){
  int time = 0;
  init();

  while (1){
    checkWater();
    if (findParent(swans[0]) == findParent(swans[1])) break;
    time++;
    meltIce();
  }
  cout << time;
}

int main(){
  input();
  solve();
  return 0;
}