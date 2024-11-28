#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, S;
int arr[20];
int answer;

void input(){
  fastio
  cin >> N >> S;
  for (int i = 0; i < N; ++i){
    cin >> arr[i];
  }
}

void findSubArr(int cur, int sum){
  if (sum == S) {
    ++answer;
  }
  for (int nxt = cur + 1; nxt < N; ++nxt){
    findSubArr(nxt, sum + arr[nxt]);
  }
}

void solve(){
  // sort(arr, arr + N);
  for (int start = 0; start < N; ++start)
    findSubArr(start, arr[start]);
  cout << answer;
}

int main(){
  input();
  solve();
  return 0;
}