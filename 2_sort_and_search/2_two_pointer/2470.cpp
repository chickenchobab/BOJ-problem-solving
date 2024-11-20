#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int l[100000];

void init(){
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> l[i];
}

void solve(){
  // 양양
  if (l[0] >= 0 && l[N - 1] >= 0)
    cout << l[0] << ' ' << l[1];
  // 음음
  else if (l[0] <= 0 && l[N - 1] <= 0)
    cout << l[N - 2] << ' ' << l[N - 1];
  // 음양
  else {
    int s = 0, e = N - 1;
    int a = l[s], b = l[e];
    int sum = abs(a + b);

    while (s < e){

      if (sum > abs(l[s] + l[e])){
        a = l[s];
        b = l[e];
        sum = abs(a + b);
      }

      if (l[s] + l[e] > 0) --e;
      else ++s;
    }
    cout << a << ' ' << b;
  }
}

int main(){
  fastio
  init();
  solve();
  return 0;
}