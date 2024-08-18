#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
string str1, str2;
int dp[1001][1001];

void input(){
  fastio
  cin >> str1 >> str2;
}

void print(int i, int j){
  if (!i || !j) return;
  if (str1[i - 1] == str2[j - 1]) {
    print(i - 1, j - 1);
    cout << str1[i - 1];
  }
  else 
    dp[i - 1][j] > dp[i][j - 1] ? print(i - 1, j) : print(i, j - 1);
}

void solve(){
  int l1 = str1.length();
  int l2 = str2.length();
  for (int i = 1; i <= l1; ++i){
    for (int j = 1; j <= l2; ++j){
      if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  cout << dp[l1][l2] << '\n';
  print(l1, l2);
}

int main(){
  input();
  solve();
  return 0;
}