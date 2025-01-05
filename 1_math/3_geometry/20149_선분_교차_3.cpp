#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define x(a) (coords[a].first)
#define y(a) (coords[a].second)
using namespace std;
using ll = long long;
using coord = pair<ll, ll>;

coord coords[4];

int checkRotation(int a, int b, int c){
  ll res = (x(b) - x(a)) * (y(c) - y(a)) - (x(c) - x(a)) * (y(b) - y(a));
  if (res > 0) return 1; // 반시계
  if (res < 0) return -1; // 시계
  return 0;
}

void checkIntersection(){
  
  int a = checkRotation(0, 2, 3);
  int b = checkRotation(1, 2, 3);
  int c = checkRotation(2, 0, 1);
  int d = checkRotation(3, 0, 1);

  if (a * b == 0 && c * d == 0){ // 선분이 한 점을 공유하거나 일직선 위에 있음
    if (a || b){ // 한 점을 공유함
      cout << "1\n";
      if (a) cout << x(1) << ' ' << y(1);
      else cout << x(0) << ' ' << y(0);
    }
    else { // 선분이 일직선에 있음
      cout << (coords[1] >= coords[2] && coords[0] <= coords[3]) << '\n';
      if (coords[1] == coords[2]) // 한 점을 공유함
        cout << x(1) << ' ' << y(1);
    }
  }
  else if (a * b <= 0 && c * d <= 0){ // 한 점에서 교차함
    double numx = (x(3) * y(2) - x(2) * y(3)) * (x(1) - x(0)) - (x(1) * y(0) - x(0) * y(1)) * (x(3) - x(2));
    double numy = (x(3) * y(2) - x(2) * y(3)) * (y(1) - y(0)) - (x(1) * y(0) - x(0) * y(1)) * (y(3) - y(2));
    double denom = (y(2) - y(3)) * (x(1) - x(0)) - (y(0) - y(1)) * (x(3) - x(2));
    cout << "1\n";
    cout.setf(ios::fixed);
    cout.precision(9);
    cout << numx / denom << ' ' << numy / denom;
  }
  else {
    cout << 0;
  }
}

void sortCoords(){
  if (coords[1] <= coords[0]) 
    swap(coords[1], coords[0]);
  if (coords[3] <= coords[2])
    swap(coords[3], coords[2]);
  if (coords[2] <= coords[0]){
    swap(coords[2], coords[0]);
    swap(coords[3], coords[1]);
  }
}

void solve(){
  sortCoords();
  checkIntersection();
}

void init(){
  for (int i = 0; i < 4; ++i)
    cin >> x(i) >> y(i);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}