#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, K;
int cost[10001], parent[10001];
bool visited[10001];
int totalCost;

void input(){
  fastio
  cin >> N >> M >> K;
  int c;
  for (int i = 1; i <= N; ++i){
    cin >> cost[i];
  }
}

int find(int x){
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);

  if (cost[a] < cost[b]){
    parent[b] = a;
  }
  else {
    parent[a] = b;
  }
}

void solve(){

  int v, w;

  for (int i = 0; i <= N; ++i)
    parent[i] = i;

  while (M--){
    cin >> v >> w;
    if (find(v) == find(w)) continue;
    merge(v, w);
  }

  for (int i = 1; i <= N; ++i){
    int p = find(i);
    if (!visited[p]){
      visited[p] = 1;
      totalCost += cost[p];
    }
  }

  if (totalCost > K) cout << "Oh no";
  else cout << totalCost;

}

int main(){
  input();
  solve();
  return 0;
}