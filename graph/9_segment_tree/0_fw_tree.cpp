#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// fenwick tree
class FWtree {
 public:
  vector<ll> tree;
  vector<ll> numbers;
  int size;

  FWtree(int t) {
    for (size = 1; size < t; size *= 2)
      ;
    tree.resize(size + 1, 0);
  }

  // update
  void update(int pos, ll diff) {
    // 최하위 비트를 더해주면서 update

    while (pos <= size) {
      tree[pos] += diff;
      pos += (pos & (-pos));
    }
  }

  // sum of numbers from one to pos
  ll query(int pos) {
    ll ret = 0;
    while (pos > 0) {
      ret += tree[pos];
      pos -= (pos & (-pos));
    }
    return ret;
  }

  ll query(int left, int right) {
    if (left == 0) return query(right);
    return query(right) - query(left - 1);
  }
};