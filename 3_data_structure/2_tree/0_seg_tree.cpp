#include <iostream>
#include <vector>
using namespace std;
using etype = long long;

// one-base segment tree
class Segtree {
private:
  vector<etype> tree;
  int size;

public:
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

  // Check subtree at idx on which start and end depend.
  etype query(int idx, int start, int end, int left, int right) {
    if (start > right || end < left)
      return 0;

    if (left <= start && end <= right)
      return tree[idx];

    int mid = (start + end) / 2;
    return query(idx * 2, start, mid, left, right) + query(idx * 2 + 1, mid + 1, end, left, right);
  }
};