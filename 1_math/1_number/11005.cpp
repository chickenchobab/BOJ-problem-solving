#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int B;

void input(){
  cin >> N >> B;
}

void solve(){
  string answer = "";
  int digit = 1;
  while (N){
    answer = (char)(N % B > 9 ? N % B - 10 + 'A' : N % B + '0') + answer;
    N /= B;
  }
  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}