#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// one-base segment tree
class Segtree {
 public:
  vector<ll> tree;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2)
      ;
    tree.resize(size * 2);
  }

  // update
  void update(int pos, ll diff) {
    int index = size + pos - 1;
    while (index) {
      tree[index] += diff;
      index /= 2;
    }
  }

  ll query(int left, int right) { return query(1, 1, size, left, right); }

  ll query(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 0;
    } else if (left <= start &&
               end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      return query(pos * 2, start, mid, left, right) +
             query(pos * 2 + 1, mid + 1, end, left, right);
    }
  }
};