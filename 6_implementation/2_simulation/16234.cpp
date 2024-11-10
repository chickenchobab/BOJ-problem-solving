#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, L, R;
vector<int> population, sumPopulation, parent;
int dr[] = {1, 0}, dc[] = {0, 1};

void input(){
  cin >> N >> L >> R;
  population.resize(N * N);
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      cin >> population[i * N + j];
    }
  }
}

int find(int x){
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

void unite(int a, int b){
  a = find(a);
  b = find(b);

  if (parent[a] < parent[b]){
    parent[a] += parent[b];
    parent[b] = a;
  }
  else {
    parent[b] += parent[a];
    parent[a] = b;
  }
}

bool isSimilar(int a, int b){
  int gap = abs(a - b);
  return gap >= L && gap <= R;
}

bool checkBorders(){
  int a, b;
  bool ret = 0;
  for (int r = 0; r < N; ++r){
    for (int c = 0; c < N; ++c){
      a = r * N + c;
      for (int dir = 0; dir < 2; ++dir){
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        b = nr * N + nc;
        if (isSimilar(population[a], population[b]) && find(a) != find(b)){
          unite(a, b);
          ret = 1;
        }
      }
    }
  }
  return ret;
}

void calcSumPopulation(){
  for (int c = 0; c < parent.size(); ++c){
    sumPopulation[find(c)] += population[c];
  }
}

void move(){
  int p, c;
  for (c = 0; c < parent.size(); ++c){
    if ((p = find(c)) == -1) continue;
    population[c] = sumPopulation[p] / parent[p] * -1;
  }
}

void init(){
  parent.assign(N * N, -1);
  sumPopulation.assign(N * N, 0);
}

void solve(){
  int answer = 0;
  while(1) {
    init();
    if (!checkBorders()) break;
    ++answer;
    calcSumPopulation();
    move();
  }
  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}