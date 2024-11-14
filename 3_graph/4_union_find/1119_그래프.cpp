#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
// Another solution : dfs
int N;
vector<pair<int, int>> edges;
vector<int> parent, numBackedge;

void init(){
  cin >> N;
  parent.assign(N + 1, -1);
  numBackedge.assign(N + 1, 0);

  string str;   
  for (int i = 1; i <= N; ++i){
    cin >> str;
    for (int j = i + 1; j <= N; ++j)
      if (str[j - 1] == 'Y')
        edges.push_back({i, j});
  }
}

int find(int x){
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b){
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

void solve(){
  int answer = 0;
  vector<int> roots;

  for (auto &[a, b] : edges){
    if (find(a) == find(b)){
      ++numBackedge[find(a)];
      continue;
    }
    merge(a, b);
  }

  // No need to change
  if (parent[find(1)] == -N){
    cout << 0;
    return;
  }

  for (int i = 1; i <= N; ++i)
    if (parent[i] < 0)
      roots.push_back(i);
  
  // Isolated set exists
  for (int &r : roots){
    if (parent[r] == -1){
      cout << -1;
      return;
    }
  }

  for (int i = 0; i < roots.size(); ++i){
    for (int j = 0; j < roots.size() && numBackedge[roots[i]]; ++j){
      if (find(roots[i]) == find(roots[j])) continue;
      // if (parent[find(roots[j])] == -1) continue;

      --numBackedge[roots[i]];
      merge(roots[i], roots[j]);
      ++answer;
    }
  }

  if (parent[find(1)] == -N) cout << answer;
  else cout << -1;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}