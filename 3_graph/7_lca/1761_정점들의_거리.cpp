#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
vector<pair<int, int>> edges[40004];
int level[40004], parent[40004], inherit[40004];

void input(){
  fastio
  cin >> N;
  int a, b, c;
  for (int i = 1; i < N; ++i){
    cin >> a >> b >> c;
    edges[a].push_back({c, b});
    edges[b].push_back({c, a});
  }
}

void makeFamily(int cur, int lev){
  level[cur] = lev;
  for (auto e : edges[cur]){
    if (e.second == parent[cur]) continue;
    parent[e.second] = cur;
    inherit[e.second] = e.first;
    makeFamily(e.second, lev + 1);
  }
}

int getDistance(int a, int b){
  int dist = 0;
  if (level[a] > level[b]) swap(a, b);

  while (level[a] != level[b]) {
    dist += inherit[b];
    b = parent[b];
  }
  
  while (a != b){
    dist += inherit[a];
    a = parent[a];
    dist += inherit[b];
    b = parent[b];
  }

  return dist;
}

void solve(){
  int a, b;
  cin >> M;
  makeFamily(1, 1);
  while (M--){
    cin >> a >> b;
    // cout << a << ' ' << b << endl;
    cout << getDistance(a, b) << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}