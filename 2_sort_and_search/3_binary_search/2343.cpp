#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
int len[100000];

void init(){
  cin >> N >> M;
  for (int i = 0; i < N; ++i)
    cin >> len[i];
}

int cntBlueray(int siz){
  int cnt = 1;
  int space = siz;

  for (int i = 0; i < N; ++i){
    if (space >= len[i])
      space -= len[i];
    else {
      if (siz < len[i]) return 0;
      ++cnt;
      space = siz - len[i];
    }
  }

  return cnt;
}

void solve(){
  int answer;
  int s = 1, e = 1e9;
  
  while (s <= e){
    int m = (s + e) / 2;

    int numBlueray = cntBlueray(m);
    if (numBlueray > M || numBlueray == 0)
      s = m + 1;
    else {
      answer = m;
      e = m - 1;
    }
  }

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}