#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
vector<int> arr;

void init(){
  cin >> N;
  arr.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> arr[i];
}

void solve(){
  int answer = 0;

  sort(begin(arr), end(arr));

  for (int i = 0; i < N; ++i){
    int s = 0, e = N - 1;

    while (s < e){
      if (e == i) {
        --e;
        continue;
      }
      else if (s == i) {
        ++s;
        continue;
      }

      int sum = arr[s] + arr[e];
      if (sum == arr[i]){
        ++answer;
        break;
      }
      else if (sum > arr[i])
        --e;
      else
        ++s;
    }
  }
  cout << answer;
} 

int main(){
  fastio
  init();
  solve();
  return 0;
}