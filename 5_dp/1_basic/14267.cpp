#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int boss[100001], laudations[100001];

void input(){
  fastio
  cin >> n >> m;
  for (int i = 1; i <= n; ++i){
    cin >> boss[i];
  }
}

void solve(){
  int i, w;
  while (m--){
    cin >> i >> w;
    laudations[i] += w;
  }
  for (int i = 2; i <= n; ++i)
    laudations[i] += laudations[boss[i]];
  for (int i = 1; i <= n; ++i)
    cout << laudations[i] << ' ';
}

int main(){
  input();
  solve();
  return 0;
}