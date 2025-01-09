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
  if (a > b) swap(a, b);
  while (a){
    int mod = b % a;
    b = a;
    a = mod;
  }
  return b;
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