#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int T;
int N;
vector<int> zeroCnt(41, -1), oneCnt(41, -1);

void input(){
  fastio
  cin >> T;
}

int getFiboZero(int x){
  if (zeroCnt[x] != -1) return zeroCnt[x];
  return zeroCnt[x] = getFiboZero(x - 1) + getFiboZero(x - 2);
}

int getFiboOne(int x){
  if (oneCnt[x] != -1) return oneCnt[x];
  return oneCnt[x] = getFiboOne(x - 1) + getFiboOne(x - 2);
}

void solve(){
  zeroCnt[0] = 1; 
  zeroCnt[1] = 0;
  oneCnt[0] = 0;
  oneCnt[1] = 1;

  while (T--){
    cin >> N;
    cout << getFiboZero(N) << ' ' << getFiboOne(N) << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}