#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
vector<int> trees;
typedef long long ll;

void input(){
  cin >> N >> M;
  trees.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> trees[i];
}

bool isEnough(int h){
  ll sum = 0;
  for (int i = 0; i < N; ++i){
    if (trees[i] <= h) continue;
    sum += trees[i] - h;
  }
  return sum >= M;
}

void solve(){
  int answer = 0;

  int s = 0, e = *max_element(trees.begin(), trees.end());
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