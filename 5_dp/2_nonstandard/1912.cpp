#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int dp[100001];

void input(){
  fastio
  cin >> n;
}

void solve(){
  int num;
  int answer = -1111111111;
  for (int i = 1; i <= n; ++i){
    cin >> num;
    dp[i] = max(dp[i - 1] + num, num);
    answer = max(answer, dp[i]);
  }
  cout << answer;
}

int main(){
  input();
  solve();
  return 0;
}