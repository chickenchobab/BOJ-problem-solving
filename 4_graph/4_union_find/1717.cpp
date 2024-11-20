#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<int> parent;

void input(){
  fastio
  cin >> n >> m;
}

int find(int x){
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);

  if (a == b) return;

  if (parent[a] < parent[b])
    parent[b] = a;
  else {
    if (parent[a] == parent[b])
      parent[b]--;
    parent[a] = b;
  }
}

void solve(){
  bool order;
  int a, b;

  parent.resize(n + 1, -1);

  while (m--){
    cin >> order >> a >> b;
    if (order) 
      find(a) == find(b) ? cout << "yes\n" : cout << "no\n";
    else
      merge(a, b);
  }
}

int main(){
  input();
  solve();
  return 0;
}