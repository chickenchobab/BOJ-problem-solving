#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

int N, K;
string num[15];
int modNum[15], modDigit[51];
ll dp[1 << 15][100];

ll getFactorial(int n){
  ll ret = 1;
  for (int i = 2; i <= n; ++i)
    ret *= i;
  return ret;
}

ll getGcd(ll a, ll b){
  if (a > b) swap(a, b);
  while (a){
    ll mod = b % a;
    b = a;
    a = mod;
  }
  return b;
}

int getMod(string &n, int k){
  int ret = 0;
  for (int i = 0; i < n.length(); ++i){
    ret *= 10;
    ret += n[i] - '0';
    ret %= k;
  }
  return ret;
}

void solve(){
  for (int i = 0; i < N; ++i)
    modNum[i] = getMod(num[i], K);
  
  modDigit[0] = 1;
  for (int i = 1; i <= 50; ++i)
    modDigit[i] = (modDigit[i - 1] * 10) % K;

  int fullMask = (1 << N);
  dp[0][0] = 1;

  for (int cur = 0; cur < fullMask; ++cur){

    for (int i = 0; i < N; ++i){ // 뒤에 추가할 숫자를 구한다.
      if (cur & (1 << i)) continue;

      int nxt = cur | (1 << i);
      for (int j = 0; j < K; ++j) // 앞 숫자의 나머지 별로 갱신한다.
        dp[nxt][(j * modDigit[num[i].length()] % K + modNum[i]) % K] += dp[cur][j];
    }
  }

  ll numTotal = getFactorial(N);
  ll gcd = getGcd(dp[fullMask - 1][0], numTotal);
  cout << dp[fullMask - 1][0] / gcd << '/' << numTotal / gcd;
}

void init(){
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> num[i];
  cin >> K;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}