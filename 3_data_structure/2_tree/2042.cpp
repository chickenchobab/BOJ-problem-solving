#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using etype = long long;

int N, M, K;

class SegTree{
public:
  int size;
  vector<etype> tree;

  SegTree(int num){
    for (size = 1; size < num; size *= 2);
    tree.resize(size * 2, 0);
  }

  void update(int pos, etype num){
    int idx = size - 1 + pos;
    etype gap = num - tree[idx];
    while (idx){
      tree[idx] += gap;
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
    return query(idx * 2, start, mid, left, right) + query(idx * 2 + 1, mid + 1, end, left, right);
  }
};

void init(){
  cin >> N >> M >> K;
}

void solve(){
  SegTree segtree(N);

  etype num;
  for (int i = 1; i <= N; ++i){
    cin >> num;
    segtree.update(i, num);
  }

  int q = M + K;
  etype a, b, c;
  while (q--){
    cin >> a >> b >> c;
    if (a == 1)
      segtree.update(b, c);
    else
      cout << segtree.query(b, c) << '\n';
  }
}

int main(){
  fastio
  init();
  solve();
  return 0;
}