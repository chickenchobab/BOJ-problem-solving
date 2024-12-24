#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int x[3], y[3];

void init(){
  for (int i = 0; i < 3; ++i)
    cin >> x[i] >> y[i];
}

void solve(){
  int crossProduct = (x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0]);
  if (crossProduct > 0)
    cout << 1;
  else if (crossProduct < 0)
    cout << -1;
  else
    cout << 0;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}