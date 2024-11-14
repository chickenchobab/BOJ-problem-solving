#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, R;
int A[301][301];
vector<vector<int>> peels;
vector<int> start;

void input(){
  fastio
  cin >> N >> M >> R;
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      cin >> A[i][j];
    }
  }
}

void peel(){
  int i, j, minR, minC, maxR, maxC;
  for (int p = 0; p < peels.size(); ++p){
    minR = p + 1, minC = p + 1, maxR = N + 1 - minR, maxC = M + 1 - minC;
    i = minR, j = minC;
    for (; i < maxR; ++i) peels[p].push_back(A[i][j]);
    for (; j < maxC; ++j) peels[p].push_back(A[i][j]);
    for (; i > minR; --i) peels[p].push_back(A[i][j]);
    for (; j > minC; --j) peels[p].push_back(A[i][j]);
  }
}

void rotate(){
  int idx, i, j, minR, minC, maxR, maxC;
  for (int p = 0; p < peels.size(); ++p){
    start[p] = (start[p] + peels[p].size() - R % peels[p].size()) % peels[p].size();
    minR = p + 1, minC = p + 1, maxR = N + 1 - minR, maxC = M + 1 - minC;
    idx = start[p], i = minR, j = minC;

    for (; i < maxR; ++i) 
      A[i][j] = peels[p][idx], idx = (idx + 1) % peels[p].size();
    for (; j < maxC; ++j) 
      A[i][j] = peels[p][idx], idx = (idx + 1) % peels[p].size();
    for (; i > minR; --i) 
      A[i][j] = peels[p][idx], idx = (idx + 1) % peels[p].size();
    for (; j > minC; --j) 
      A[i][j] = peels[p][idx], idx = (idx + 1) % peels[p].size();
  }
}

void solve(){
  peels.resize(min(N, M) / 2);
  start.resize(min(N, M) / 2, 0);
  peel();
  rotate();
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      cout << A[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}