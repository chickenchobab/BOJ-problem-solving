#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
long long M;
vector<int> requests;

void input(){
  cin >> N;
  requests.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> requests[i];
  cin >> M;
}

bool isEnough(int limit){
  long long sum = 0;
  for (int i = 0; i < N; ++i){
    sum += min(limit, requests[i]);
  }
  return sum <= M;
}

void solve(){
  int answer = 0;
  int s = 1, e = *max_element(requests.begin(), requests.end());
  
  while (s <= e){
    int m = (s + e) / 2;

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