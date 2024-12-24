#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int x[2], y[2];
int n;
vector<tuple<int, int, int>> planets;

void init(){
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  cin >> n;
}

void solve(){
  int answer = 0;
  int a, b, r;

  while (n--){
    cin >> a >> b >> r;

    if (pow(x[0] - a, 2) + pow(y[0] - b, 2) < r * r){
      if (pow(x[1] - a, 2) + pow(y[1] - b, 2) > r * r)
        ++answer;
    }
    else {
      if (pow(x[1] - a, 2) + pow(y[1] - b, 2) < r * r)
        ++answer;
    }
  }

  cout << answer << '\n';
}

int main(){
  fastio
  int T;
  cin >> T;
  while (T--){
    init();
    solve();
  }
  return 0;
}