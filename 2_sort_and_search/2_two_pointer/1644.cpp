#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
vector<bool> isPrime;

void init(){
  cin >> N;
  isPrime.resize(N + 1);
}

void solve(){
  int answer = 0;

  fill(begin(isPrime) + 2, end(isPrime), 1);

  for (int i = 2; i <= sqrt(N); ++i){
    if (!isPrime[i]) 
      continue;
    for (int j = i * i; j <= N; j += i)
      isPrime[j] = 0;
  }

  int sum = 0;
  int s = 1;
  for (int e = 2; e <= N; ++e){
    if (!isPrime[e])
      continue;
    sum += e;
    while (s <= e && sum > N){
      if (isPrime[s])
        sum -= s;
      ++s;
    }
    answer += (sum == N);
  }

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}