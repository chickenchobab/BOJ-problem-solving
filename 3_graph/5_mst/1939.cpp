#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M, X, Y;
typedef struct EDGE{
  int a, b, d;
}edge;
bool cmp(const edge &a, const edge &b){
  return a.d > b.d;
}
vector<edge> edges;
vector<int> parent;

void input(){
  fastio
  cin >> N >> M;
  int a, b, d;
  for (int e = 1; e <= M; ++e){
    cin >> a >> b >> d;
    edges.push_back({a, b, d});
  }
  cin >> X >> Y;
}

int find(int x){
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);

  if (parent[a] < parent[b]) 
    parent[b] = a;
  else {
    if (parent[a] == parent[b])
      parent[b]--;
    parent[a] = b;
  }
}

void solve(){

  int ans;
  parent.resize(N + 1, -1);

  sort(edges.begin(), edges.end(), cmp);
  for (edge &e : edges){
    if (find(e.a) == find(e.b)) continue;
    merge(e.a, e.b);
    if (find(X) == find(Y)) {
      ans = e.d;
      break;
    }
  }

  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}