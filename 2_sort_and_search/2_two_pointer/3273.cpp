#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int arr[100001];
int x;

void init(){
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  cin >> x;
}

void solve(){
  int answer = 0;
  int s = 1, e = n;

  sort(arr + 1, arr + n + 1);

  for (; e >= 1; --e){
    while (s < e && arr[s] + arr[e] < x)
     ++s;
    answer += (s < e && arr[s] + arr[e] == x);
  }

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}