#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
bool visited[9];
int numbers[9];
vector<int> arr;
// map<vector<int>, bool> printed;

void input(){
  fastio
  cin >> N >> M;
  for (int i = 1; i <= N; ++i){
    cin >> numbers[i];
  }
}

void pickNumber(int cur, int depth){
  if (depth == M){
    for (auto o : arr){
      cout << o << ' ';
    }
    cout << '\n';
    return;
  }

  int prvNum = 0;
  for (int nxt = 1; nxt <= N; ++nxt){
    if (visited[nxt]) continue;
    if (numbers[nxt] == prvNum) continue;
    prvNum = numbers[nxt];

    visited[nxt] = 1;
    arr.push_back(numbers[nxt]);
    pickNumber(nxt, depth + 1);
    visited[nxt] = 0;
    arr.pop_back();
  }
}

void solve(){
  sort(numbers + 1, numbers + N + 1);
  pickNumber(0, 0);
}

int main(){
  input();
  solve();
  return 0;
}