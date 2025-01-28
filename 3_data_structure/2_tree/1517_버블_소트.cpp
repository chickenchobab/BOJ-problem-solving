#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class SegmentTree{
private:
  int size;
  vector<int> tree;

public:
  SegmentTree(int n){
    for (size = 1; size <= n; size *= 2);
    tree.assign(size * 2, 0);
  }

  void update(int pos, int val){
    int idx = size + pos - 1;
    while (idx){
      tree[idx] += val;
      idx /= 2;
    }
  }

  int query(int left, int right){
    return query(1, 1, size, left, right);
  }

  int query(int idx, int start, int end, int left, int right){
    if (right < start || end < left)
      return 0;
    if (left <= start && end <= right)
      return tree[idx];
    int mid = (start + end) / 2;
    return query(2 * idx, start, mid, left, right) + query(2 * idx + 1, mid + 1, end, left, right);
  }
};

int N;
pair<int, int> A[500000];
SegmentTree st(500000);

void solve(){
  long long answer = 0;

  sort(A, A + N);

  for (int i = 0; i < N; ++i){
    // Find smaller number with bigger index.
    answer += st.query(A[i].second, N);
    st.update(A[i].second, 1);
  }

  cout << answer;
}

void init(){
  cin >> N;
  int num;
  for (int i = 0; i < N; ++i){
    cin >> num;
    A[i] = {num, i + 1};
  }
}


int main(){
  fastio
  init();
  solve();
  return 0;
}