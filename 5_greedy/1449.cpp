#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, L;
int pos[1001];

void input(){
  cin >> N >> L;
  for (int i = 1; i <= N; ++i)
    cin >> pos[i];
}

void solve(){
  int answer = 0;

  sort(pos + 1, pos + N + 1);
  int s = 1;
  for (int e = 1; e <= N; ++e){
    if (pos[e] - pos[s] + 1 <= L) continue;
    ++answer;
    s = e;
  }
  cout << answer + 1;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}