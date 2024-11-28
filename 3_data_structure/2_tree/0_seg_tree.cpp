#include <iostream>
#include <vector>
using namespace std;
using etype = long long;

// one-base segment tree
class Segtree {
 public:
  vector<etype> tree;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2);
    tree.resize(size * 2);
  }

  void update(int pos, etype diff) {
    int index = size + pos - 1;
    while (index) {
      tree[index] += diff;
      index /= 2;
    }
  }

  etype query(int left, int right) { return query(1, 1, size, left, right); }

  etype query(int idx, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 0;
    } else if (left <= start && end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[idx];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      return query(idx * 2, start, mid, left, right) +
             query(idx * 2 + 1, mid + 1, end, left, right);
    }
  }
};