#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int m, q;
int state[20][200001];

void setSparseTable(){
  cin >> m;
  for (int x = 1; x <= m; ++x)
    cin >> state[0][x];
  for (int i = 1; i < 20; ++i)
    for (int j = 1; j <= m; ++j)
      state[i][j] = state[i - 1][state[i - 1][j]];
}

void handleQueries(){
  cin >> q;
  while (q--){
    int n, x;
    cin >> n >> x;

    for (int k = 0; k < 20; ++k)
      if (n & (1 << k))
        x = state[k][x];

    cout << x << '\n';
  }
}

int main(){
  fastio
  setSparseTable();
  handleQueries();
  return 0;
}