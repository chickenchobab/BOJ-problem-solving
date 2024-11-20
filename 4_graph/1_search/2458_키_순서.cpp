#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
vector<int> smaller[501], bigger[501];
int isVisited[501];
int numVisit; // Not to reset the visit array.

void init(){
  cin >> N >> M;
  int a, b;
  for (int i = 1; i <= M; ++i){
    cin >> a >> b;
    smaller[a].push_back(b);
    bigger[b].push_back(a);
  }
}

int calcSmaller(int cur){
  int ret = 1;
  isVisited[cur] = numVisit;

  for (int nxt : smaller[cur]){
    if (isVisited[nxt] == numVisit) continue;
    ret += calcSmaller(nxt);
  }
  return ret;
}

int calcBigger(int cur){
  int ret = 1;
  isVisited[cur] = numVisit;

  for (int nxt : bigger[cur]){
    if (isVisited[nxt] == numVisit) continue;
    ret += calcBigger(nxt);
  }
  return ret;
}

void solve(){
  int answer = 0;
  int numSmaller, numBigger;

  for (int i = 1; i <= N; ++i){
    ++numVisit;
    numSmaller = calcSmaller(i) - 1;
    ++numVisit;
    numBigger = calcBigger(i) - 1;
    answer += (numSmaller + numBigger == N - 1);
  }
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}