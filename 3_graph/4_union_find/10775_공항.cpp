#include <iostream> 
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int G, P;
int parent[100001];

void input(){
  fastio
  cin >> G >> P;
}

int find(int x){
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void solve(){
  int dockCnt = 0;

  for (int g = 1; g <= G; ++g)
    parent[g] = g;

  int gate;
  for (int p = 1; p <= P; ++p){
    cin >> gate;
    gate = find(gate);
    if (!gate) break;
    parent[gate] = find(gate - 1);
    dockCnt++;
  }

  cout << dockCnt;
}

int main(){
  input();
  solve();
  return 0;
}