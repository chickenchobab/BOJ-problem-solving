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

struct line{
  point start, end;
};

line u, v;
point points[4];

void init(){
  int a, b, c, d;
  for (int i = 0; i < 2; ++i){
    cin >> a >> b >> c >> d;
    u = {{a, b}, {c, d}};
  }
}

int checkRotation(point& a, point& b, point& c){
  ll res = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
  if (res > 0) return 1; // counterclockwise
  if (res < 0) return -1; // clockwise
  return 0; // aligned
}

bool haveIntersection(){
  int a = checkRotation(u.start, v.start, v.end);
  int b = checkRotation(u.end, v.start, v.end);
  int c = checkRotation(v.start, u.start, u.end);
  int d = checkRotation(v.end, u.start, u.end);

  if (a * b <= 0 && c * d <= 0){
    if (a * b == 0 && c * d == 0){ // sharing point or aligned
      if (u.end <= u.start) 
        swap(u.end, u.start);
      if (v.end <= v.start)
        swap(v.end, v.start);
      return v.start <= u.end && u.start <= v.end;
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