#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int m;
int state[20][200001];

void solve(){
  int Q;
  cin >> Q;
  while (Q--){
    int n, x;
    cin >> n >> x;
    for (int k = 0; k < 20; ++k)
      if (n & (1 << k))
        x = state[k][x];
    cout << x << '\n';
  }
}

void init(){
  cin >> m;
  for (int j = 1; j <= m; ++j)
    cin >> state[0][j];
  
  for (int i = 1; i < 20; ++i)
    for (int j = 1; j <= m; ++j)
      state[i][j] = state[i - 1][state[i - 1][j]];
}

int main(){
  fastio
  init();
  solve();
  return 0;
}