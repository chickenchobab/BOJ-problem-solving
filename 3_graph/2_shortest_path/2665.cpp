#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int n;
bool map[51][51];
int visited[51][51];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
deque<pair<int, int>> dq;

void input(){
  fastio
  cin >> n;
  string str;
  for (int i = 1; i <= n; ++ i){
    cin >> str;
    for (int j = 1; j <= n; ++ j){
      map[i][j] = str[j - 1] - '0';
    }
  }
}

void bfs(){
  dq.push_back({1, 1});
  visited[1][1] = 1;

  while (dq.size()){
    int i = dq.front().first;
    int j = dq.front().second;
    dq.pop_front();

    for (int d = 0; d < 4; ++ d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 1 || ni > n || nj < 1 || nj > n) continue;
      if (visited[ni][nj]) continue;

      if (!map[ni][nj]){
        dq.push_back({ni, nj});
        visited[ni][nj] = visited[i][j] + 1;
      }
      else{
        dq.push_front({ni, nj});
        visited[ni][nj] = visited[i][j];
      }
    }
  }

}

void solve(){
  bfs();
  cout << visited[n][n] - 1;
}

int main(){
  input();
  solve();
  return 0;
}