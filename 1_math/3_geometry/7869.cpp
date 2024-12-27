#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PI (3.14159265358979323846)

using namespace std;

typedef struct CIRCLE{
  double x, y, r;
}circle;

circle u, v;

void init(){
  cin >> u.x >> u.y >> u.r >> v.x >> v.y >> v.r;
  if (u.r > v.r)
    swap(u, v);
}

double getDist(double a, double b, double c, double d){
  return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

double getTheta(double a, double b, double c){
  return acos((a * a + b * b - c * c) / (2 * a * b));
}

void solve(){
  double answer = 0;
  double dist = getDist(u.x, u.y, v.x, v.y);
  
  if (dist < u.r + v.r){
    if (dist + u.r <= v.r) {// 큰 원이 작은 원을 포함한다다
      answer = PI * u.r * u.r;
    }
    else { // 일부가 겹친다
      double a = getTheta(u.r, dist, v.r);
      double b = getTheta(v.r, dist, u.r);
      answer = u.r * u.r * a - 0.5 * u.r * u.r * sin(2 * a) + v.r * v.r * b - 0.5 * v.r * v.r * sin(2 * b);
    }
  }

  cout << fixed << setprecision(3) << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}