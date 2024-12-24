#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

vector<int> powers;

void init(){
  powers.resize(8);
  for (int i = 0; i < 8; ++i)
    cin >> powers[i];
}

void solve(){
  int answer = 0;

  vector<int> indices(8);
  for (int i = 0; i < 8; ++i)
    indices[i] = i;

  do { // Can be solved with CCW
    bool isConvex = 1;
    for (int i = 0; i < 8; ++i){
      ll a = powers[indices[i]];
      ll b = powers[indices[(i + 1) % 8]];
      ll c = powers[indices[(i + 2) % 8]];
      if (b * b * (a + c) * (a + c) < 2 * a * a * c * c){
        isConvex = 0;
        break;
      }
    }
    answer += isConvex;
  } while (next_permutation(begin(indices), end(indices)));

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}