#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int arr[10001];

void init(){
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
}

void solve(){
  int answer = 0;

  sort(arr + 1, arr + n + 1);

  answer = max(answer, arr[n] * arr[n - 1] * arr[n - 2]);
  answer = max(answer, arr[n] * arr[n - 1]);
  answer = max(answer, arr[1] * arr[2] * arr[n]);
  answer = max(answer, arr[1] * arr[2]);
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}