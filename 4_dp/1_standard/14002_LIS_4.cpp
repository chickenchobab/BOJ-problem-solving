#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int N;
int A[1001], dp[1001], bt[1001];

void input(){
  fastio
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
}

void print(int i){
  if (!i) return;
  print(bt[i]);
  cout << A[i] << ' ';
}

void solve(){
  int lisLen = 0, lisBack = 0;

  for (int i = 1; i <= N; ++i){
    dp[i] = 1;
    for (int j = 1; j < i; ++j){
      if (A[i] > A[j] && dp[j] + 1 > dp[i]){
        dp[i] = dp[j] + 1;
        bt[i] = j;
      }
    }
  }

  for (int i = 1; i <= N; ++i){
    if (dp[i] > lisLen){
      lisLen = dp[i];
      lisBack = i;
    }
  }

  cout << lisLen << '\n';
  print(lisBack);
}

int main(){
  input();
  solve();
  return 0;
}