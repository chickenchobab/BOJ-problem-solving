#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001
using namespace std;

int N;
vector<bool> isPrime;

void init(){
  isPrime.assign(MAX, 1);
  for (int i = 2; i <= sqrt(MAX); ++i){
    if (!isPrime[i])
      continue;
    for (int j = i * i; j <= MAX; j += i)
      isPrime[j] = 0;
  }
}

void solve(){
  int T;
  cin >> T;
  while (T--){
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 2; i <= N / 2; ++i)
      answer += (isPrime[i] && isPrime[N - i]);
    cout << answer << '\n';
  }
}

int main(){
  fastio
  init();
  solve();
  return 0;
}