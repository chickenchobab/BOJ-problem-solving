#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
int p[500001], q[500001];
int dy;

void init(){
  cin >> n >> m;
  int a, b;
  cin >> a >> b;
  dy = abs(a - b);
  for (int i = 1; i <= n; ++i)
    cin >> p[i];
  for (int j = 1; j <= m; ++j)
    cin >> q[j];
}

void solve(){
  int dx = 3e8;
  int cnt;

  sort(p + 1, p + n + 1);
  sort(q + 1, q + m + 1);

  int i = 1, j = 1;

  while (i <= n && j <= m){
    int diff = p[i] - q[j];
    int absDiff = abs(diff);

    if (dx > absDiff){
      dx = absDiff;
      cnt = 1;
    }
    else if (dx == absDiff)
      ++cnt;
    
    if (diff > 0) ++j;
    else ++i;
  }

  cout << dx + dy << ' ' << cnt;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}