#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using etype = int;

int N, M, K;

class SegTree{
public:
  int size;
  vector<etype> tree;

  SegTree(int num){
    for (size = 1; size < num; size *= 2);
    tree.resize(size * 2, 1);
  }

  void update(int pos, etype num){
    int idx = size - 1 + pos;
    tree[idx] = num;
    idx /= 2;
    while (idx){
      tree[idx] = (long long)tree[idx * 2] * tree[idx * 2 + 1] % 1000000007;
      idx /= 2;
    }
  }

  etype query(int left, int right){
    return query(1, 1, size, left, right);
  }

  etype query(int idx, int start, int end, int left, int right){
    if (start > right || end < left)
      return 1;
    if (left <= start && end <= right)
      return tree[idx];
    int mid = (start + end) / 2;
    long long a = query(idx * 2, start, mid, left, right);
    long long b = query(idx * 2 + 1, mid + 1, end, left, right);
    return a * b % 1000000007;
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