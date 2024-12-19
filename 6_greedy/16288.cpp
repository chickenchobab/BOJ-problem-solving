#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, K;
int P[101];

void init(){
  cin >> N >> K;
  for (int i = N; i >= 1; --i)
    cin >> P[i];
}

void solve(){
  vector<int> backs;

  backs.push_back(P[1]);

  for (int i = 2; i <= N; ++i){

    if (backs.back() < P[i]){
      if (backs.size() == K){
        cout << "NO";
        return;
      }
      backs.push_back(P[i]);
      // cout << "insert:" << P[i] << endl;
    }
    else {
      int pos = lower_bound(begin(backs), end(backs), P[i]) - begin(backs);
      // cout << "replace: " << backs[pos]  << " with " << P[i] << endl;
      backs[pos] = P[i];
    }
  }

  cout << "YES";
}

int main(){
  fastio
  init();
  solve();
  return 0;
}