#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using etype = int;

int N;
int height[100001];

class SegTree{
public:
  int size;
  vector<etype> tree;

  SegTree(int num){
    for (size = 1; size < num; size *= 2);
    tree.resize(size * 2);
  }

  void update(int pos, etype num){
    int idx = size - 1 + pos;
    tree[idx] = num;
    idx /= 2;
    while (idx){
      if (height[tree[idx * 2]] < height[tree[idx * 2 + 1]])
        tree[idx] = tree[idx * 2];
      else 
        tree[idx] = tree[idx * 2 + 1];
      idx /= 2;
    }
  }

  etype query(int left, int right){
    return query(1, 1, size, left, right);
  }

  etype query(int idx, int start, int end, int left, int right){
    if (start > right || end < left)
      return 0;
    if (left <= start && end <= right)
      return tree[idx];
    int mid = (start + end) / 2;
    int a = query(idx * 2, start, mid, left, right);
    int b = query(idx * 2 + 1, mid + 1, end, left, right);
    if (height[a] < height[b]) return a;
    return b;
  } 
};

void init(){
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> height[i];
}

int getMaxRectArea(SegTree &segtree, int left, int right){
  if (left > right)
    return 0;
  int idx = segtree.query(left, right);
  int area = height[idx] * (right - left + 1);

  int a = getMaxRectArea(segtree, left, idx - 1);
  int b = getMaxRectArea(segtree, idx + 1, right);
  return max(max(a, b), area);
}

void solve(){
  height[0] = 1000000000;
  SegTree segtree(N);
  for (int i = 1; i <= N; ++i)
    segtree.update(i, i);
  cout << getMaxRectArea(segtree, 1, N);
}

int main(){
  fastio
  init();
  solve();
  return 0;
}