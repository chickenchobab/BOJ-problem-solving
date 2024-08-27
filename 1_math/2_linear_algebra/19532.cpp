#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int a, b, c, d, e, f;

void input(){
  cin >> a >> b >> c >> d >> e >> f;
}

void solve(){
  int x, y, determ;
  determ = a * e - b * d;
  x = (c * e - b * f) / determ;
  y = (a * f - c * d) / determ;
  cout << x << ' ' << y;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}