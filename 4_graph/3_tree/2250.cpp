#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int leftChild[10001], rightChild[10001];
int leftMost[10001], rightMost[10001];

void findAnswer(){
  int level;
  int width = 0;

  for (int l = 1; l <= N; ++l){
    if (int w = rightMost[l] - leftMost[l] + 1; width < w){
      level = l;
      width = w;
    }
  }

  cout << level << ' ' << width;
}

int dfs(int cur, int row, int col){ // 최근 갱신된 행과 열
  int ret;

  ++row;
  if (leftChild[cur] != -1)
    ret = col = dfs(leftChild[cur], row, col) + 1;
  else
    ret = ++col;

  leftMost[row] = min(leftMost[row], col);
  rightMost[row] = max(rightMost[row], col);

  if (rightChild[cur] != -1)
    return dfs(rightChild[cur], row, col);
  return ret;
}

int findRoot(){
  int root = N * (N + 1) / 2;

  for (int i = 1; i <= N; ++i){
    if (leftChild[i] != -1)
      root -= leftChild[i];
    if (rightChild[i] != -1)
      root -= rightChild[i];
  }
  return root;
}

void init(){
  cin >> N;
  int parent;
  for (int i = 1; i <= N; ++i)
    cin >> parent >> leftChild[parent] >> rightChild[parent];
  fill(leftMost + 1, leftMost + N + 1, N);
}

int main(){
  fastio
  init();
  dfs(findRoot(), 0, 0);
  findAnswer();
  return 0;
}