#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

struct point{
  ll x, y;
  bool operator <=(point &p){
    if (x == p.x)
      return y <= p.y;
    return x <= p.x;
  }
};
point points[4];

void init(){
  for (int i = 0; i < 4; ++i)
    cin >> points[i].x >> points[i].y;
}

int checkClockwise(int a, int b, int c){
  ll res = (points[b].x - points[a].x) * (points[c].y - points[a].y) - (points[c].x - points[a].x) * (points[b].y - points[a].y);
  if (res > 0) return 1; // counterclockwise
  if (res < 0) return -1; // clockwise
  return 0; // aligned
}

bool haveIntersection(){
  int a = checkClockwise(0, 2, 3);
  int b = checkClockwise(1, 2, 3);
  int c = checkClockwise(2, 0, 1);
  int d = checkClockwise(3, 0, 1);

  if (a * b <= 0 && c * d <= 0){
    if (a * b == 0 && c * d == 0){ // sharing point or aligned
      if (points[1] <= points[0]) 
        swap(points[1], points[0]);
      if (points[3] <= points[2])
        swap(points[3], points[2]);
      return points[2] <= points[1] && points[0] <= points[3];
    }
    return true;
  }
  return false;
}

void solve(){
  cout << haveIntersection();
}

int main(){
  fastio
  init();
  solve();
  return 0;
}