#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int k;
int S[50];
vector<int> result;

void input(){
  fastio
}

void pickNumber(int cur, int cnt){

  if (cnt == 6) {
    for (int &res : result) cout << res << ' ';
    cout << '\n';
    return;
  }

  for (int nxt = cur + 1; nxt <= k; ++nxt){
    result.push_back(S[nxt]);
    pickNumber(nxt, cnt + 1);
    result.pop_back();
  }
}

void solve(){
  while (1){
    cin >> k;
    if (!k) return;
    for (int i = 1; i <= k; ++i)
      cin >> S[i];
    pickNumber(0, 0);
    cout << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}