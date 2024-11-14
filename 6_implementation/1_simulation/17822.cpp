#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, T;
int plates[50][50];
int cnt;
vector<vector<bool>> isDeleted;
vector<int> heads;

void input(){
  cin >> N >> M >> T;
  heads.assign(N, 0);
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < M; ++j){
      cin >> plates[i][j];
    }
  }
}

void rotatePlate(int x, int d, int k){
  int offset = d ? k % M : M - k % M;

  for (int plate = 0; plate < N; ++plate){
    if ((plate + 1) % x) continue;
    heads[plate] = (heads[plate] + offset) % M;
  }
}

bool checkNeighbors(){
  bool ret = 0;
  int plate, offset, sector;
  isDeleted.assign(N, vector<bool>(M, 0));

  for (plate = 0; plate < N; ++plate){
    for (offset = 0; offset < M; ++offset){
      sector = (heads[plate] + offset) % M;
      if (plates[plate][sector] == 0)
        continue;
      if (plates[plate][sector] == plates[plate][(sector + 1) % M]){
        ret = 1;
        isDeleted[plate][sector] = isDeleted[plate][(sector + 1) % M] = 1;
      }
    }
  }
  for (plate = 0; plate < N - 1; ++plate){
    for (offset = 0; offset < M; ++offset){
      sector = (heads[plate] + offset) % M;
      if (plates[plate][sector] == 0)
        continue;
      if (plates[plate][sector] == plates[plate + 1][(heads[plate + 1] + offset) % M]){
        ret = 1;
        isDeleted[plate][sector] = isDeleted[plate + 1][(heads[plate + 1] + offset) % M] = 1;
      }
    }
  }
  return ret;
}

void cleanPlates(){
  int plate, sector;
  for (plate = 0; plate < N; ++plate){
    for (sector = 0; sector < M; ++sector){
      if (isDeleted[plate][sector]){
        --cnt;
        plates[plate][sector] = 0;
      }
    }
  }
}

int getTotal(){
  int sum = 0;
  int plate, sector;
  for (plate = 0; plate < N; ++plate){
    for (sector = 0; sector < M; ++sector){
      sum += plates[plate][sector];
    }
  }
  return sum;
}

void flattenPlates(){
  int plate, sector;
  float avg;

  // Calculate average
  avg = (float)getTotal() / (float)cnt;

  // Flatten
  for (plate = 0; plate < N; ++plate){
    for (sector = 0; sector < M; ++sector){
      if (plates[plate][sector] == 0)
        continue;
      if (plates[plate][sector] > avg)
        plates[plate][sector]--;
      else if (plates[plate][sector] < avg)
        plates[plate][sector]++;
    }
  }
}



void solve(){
  int x, d, k;
  cnt = N * M;
  while (T--){
    cin >> x >> d >> k;
    rotatePlate(x, d, k);
    if (checkNeighbors())
      cleanPlates();
    else
      flattenPlates();
  }
  cout << getTotal();
}

int main(){
  fastio
  input();
  solve();
  return 0;
}