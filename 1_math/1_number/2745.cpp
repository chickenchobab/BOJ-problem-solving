#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string N;
int B;

void input(){
  cin >> N >> B;
}

void solve(){
  int answer = 0;
  int digit = 1;
  for (int i = N.length() - 1; i >= 0; --i){
    if (isalpha(N[i])) answer += digit * (N[i] - 'A' + 10);
    else answer += digit * (N[i] - '0');
    digit *= B;
  }
  cout << answer;
}

int main(){
  fastio
  input();
  solve();
  return 0;
}