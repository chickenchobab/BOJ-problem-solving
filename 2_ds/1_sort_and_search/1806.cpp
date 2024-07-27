#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int N, S;
int sum[100001];

void input(){
  fastio
  cin >> N >> S;
}

void solve(){
  int s = 1, e = 1, ans = 100000;
  for (e = 1; e <= N; ++ e){
    cin >> sum[e];
    sum[e] += sum[e - 1];
    while (sum[e] - sum[s - 1] >= S){
      ans = min(ans, e - s + 1);
      s ++;
    }
  }
  if (ans == 100000) cout << 0;
  else cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}