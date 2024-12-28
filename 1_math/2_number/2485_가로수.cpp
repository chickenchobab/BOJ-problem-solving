#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int tree[100001];

void init(){
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> tree[i];
}

int getGcd(int a, int b){
  int ret = min(a, b);
  while (ret > 1){
    if (a % ret == 0 && b % ret == 0)
      return ret;
    --ret;
  }
  return ret;
}

void solve(){
  int term = tree[2] - tree[1];
  for (int i = 3; i <= N; ++i)
    term = getGcd(term, tree[i] - tree[i - 1]);
  cout << (tree[N] - tree[1]) / term + 1 - N;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}