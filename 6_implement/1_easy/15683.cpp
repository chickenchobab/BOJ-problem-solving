#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int model[9][9];
bool watched[9][9];
vector<pair<int, int>> cams;
int dir[9];
int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
int ans, wall;


void input(){
  fastio
  cin >> N >> M;
  int num;
  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= M; ++ j){
      cin >> num;
      model[i][j] = num;
      if (num == 6) wall ++;
      else if (num) cams.push_back({i, j});
    }
  }
}

void watch(int i, int j, int d){
  d %= 4;
  while (1){
    watched[i][j] = 1;
    i = i + di[d], j = j + dj[d];
    if (i < 1 || i > N || j < 1 || j > M) return;
    if (model[i][j] == 6) return;
  }
}

void get_ans(){
  int no = 0;
  for (int i = 1; i <= N; ++ i){
    for (int j = 1; j <= M; ++ j){
      if(watched[i][j] == 0) no ++;
      watched[i][j] = 0;
    }
  }
  ans = min(ans, no - wall);
}

void set_dir(int cur){
  int i, j, d;

  if (cur == cams.size()){
    for (int c = 0; c < cams.size(); ++ c){
      i = cams[c].first, j = cams[c].second;
      d = dir[c];
      watch(i, j, d);
      if (model[i][j] != 1 && model[i][j] != 3) watch(i, j, (d + 2));
      if (model[i][j] != 1 && model[i][j] != 2) watch(i, j, (d + 3));
      if (model[i][j] == 5) watch(i, j, (d + 1));
    }
    get_ans();
    return;
  }

  for (d = 0; d < 4; ++ d){
    dir[cur] = d;
    set_dir(cur + 1);
  }
}

void solve(){
  ans = 8 * 8;
  set_dir(0);
  cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}