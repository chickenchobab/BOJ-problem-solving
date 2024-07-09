#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int N, M, x, y;
vector<int> edges[50005];
int parent[50005];
bool visited[50005];
int ans;

void input(){
  fastio
  cin >> N;
  int a, b;
  for (int i = 1; i < N; ++ i){
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
}

void make_family(int cur){
  for (int nxt : edges[cur]){
    if (parent[nxt]) continue;
    // cout << cur << " to " << nxt << '\n';
    parent[nxt] = cur;
    make_family(nxt);
  }
}

void find_parent(int cur){
  while (parent[cur] != -1){
    if (visited[cur]){
      ans = cur;
      return;
    }
    visited[cur] = 1;
    cur = parent[cur];
  }
}

void solve(){
  parent[1] = -1;
  make_family(1);
  cin >> M;

  while (M --){
    ans = 1;
    for (int i = 1; i <= N; ++ i)
      visited[i] = 0;

    cin >> x >> y;
    find_parent(x); find_parent(y);
    cout << ans << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}