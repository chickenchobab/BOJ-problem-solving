#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int X, Y;
double D, T;

void solve(){
  cout << fixed;
  cout.precision(9);

  double dist = sqrt(X * X + Y * Y);

  if (T >= D){
    cout << dist;
  }
  else {
    double answer = dist;

    int numJump = dist / D;
    dist -= numJump * D;

    if (!numJump) answer = min(answer, min(T + D - dist, 2 * T));
    else answer = min(answer, min(numJump * T + dist, (numJump + 1) * T));
    cout << answer;
  }
}

void init(){
  cin >> X >> Y >> D >> T;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}