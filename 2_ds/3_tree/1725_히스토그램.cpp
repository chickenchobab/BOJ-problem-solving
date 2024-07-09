#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
using etype = long long;

int n;
int height[100001];

// one-base segment tree
class Segtree {
 public:
  vector<etype> tree;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2);
    tree.resize(size * 2);
  }

  // update
  void update(int pos, etype num) {
    int index = size + pos - 1;
    tree[index] = num;
    index /= 2;
    while (index) {
      if(height[tree[index * 2]] < height[tree[index * 2 + 1]]) tree[index] = tree[index * 2];
      else tree[index] = tree[index * 2 + 1];
      index /= 2;
    }
  }

  etype query(int left, int right) { return query(1, 1, size, left, right); }

  etype query(int pos, int start, int end, int left, int right) {
    if (start > right || end < left) {  // 구하려는 구간이 밖에 있는 경우
      return 0;
    } else if (left <= start && end <= right) {  // 구하려는 구간이 완전히 안에 있는 경우
      return tree[pos];
    } else {  // 구하려는 구간이 걸쳐 있는 경우
      int mid = (start + end) / 2;
      etype a = query(pos * 2, start, mid, left, right);
      etype b = query(pos * 2 + 1, mid + 1, end, left, right);
      if (height[a] < height[b]) return a;
      return b;
    }
  }

  etype calculate(int left, int right){

    int idx = query(left, right);
    int h = height[idx];
    // cout << h << ' ';

    etype area = h * (right - left + 1);
    
    if (left < idx) area = max(area, calculate(left, idx - 1));
    if (idx < right) area = max(area, calculate(idx + 1, right));
    return area;
  }
};

void input(){
    fastio
    cin >> n;
}

void solve(){
    Segtree segtree(n);
    int ans = 0;
    height[0] = 1000000000;
    for (int i = 1; i <= n; i ++){
        cin >> height[i];
        segtree.update(i, i); 
    }
    ans = segtree.calculate(1, n);
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}