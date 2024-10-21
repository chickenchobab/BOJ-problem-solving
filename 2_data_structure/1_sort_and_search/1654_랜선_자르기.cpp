#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int K, N;
vector<long long> lines;

void input(){
  cin >> K >> N;
  lines.resize(K);
  for (int i = 0; i < K; ++i)
    cin >> lines[i];
}

bool isEnough(int unit){
  int cnt = 0;
  for (int line : lines){
    cnt += line / unit;
  }
  return cnt >= N;
}

void solve(){
  int answer = 0;
  long long s = 1, e = *max_element(lines.begin(), lines.end());

  while (s <= e){
    long long m = (s + e) / 2;

    if (isEnough(m)){
      answer = m;
      s = m + 1;
    }
    else {
      e = m - 1;
    }
  }
  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}