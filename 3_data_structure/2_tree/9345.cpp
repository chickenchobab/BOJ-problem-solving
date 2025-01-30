#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MIN 0
#define MAX 100001
using namespace std;
using range = pair<int, int>;

class SegmentTree{
private:
  int size;
  vector<int> minTree, maxTree;

public:
  SegmentTree(int n){
    for (size = 1; size <= n; size *= 2);
    minTree.assign(size * 2, MAX);
    maxTree.resize(size * 2, MIN);

    int idx = size - 1;
    for (int i = 1; i <= n; ++i)
      minTree[idx + i] = maxTree[idx + i] = i;
  }

  void update(int a, int b){
    int idx;

    swap(minTree[size + a - 1], minTree[size + b - 1]);
    swap(maxTree[size + a - 1], maxTree[size + b - 1]);

    idx = (size + a - 1) / 2;
    while (idx){
      minTree[idx] = min(minTree[idx * 2], minTree[idx * 2 + 1]);
      maxTree[idx] = max(maxTree[idx * 2], maxTree[idx * 2 + 1]);
      idx /= 2;
    }

    idx = (size + b - 1) / 2;
    while (idx){
      minTree[idx] = min(minTree[idx * 2], minTree[idx * 2 + 1]);
      maxTree[idx] = max(maxTree[idx * 2], maxTree[idx * 2 + 1]);
      idx /= 2;
    }
  }

  range getMinMax(int left, int right){
    return getMinMax(1, 1, size, left, right);
  }

  range getMinMax(int idx, int start, int end, int left, int right){
    if (end < left || start > right)
      return {MAX, MIN};
    if (left <= start && end <= right)
      return {minTree[idx], maxTree[idx]};

    int mid = (start + end) / 2;
    range a = getMinMax(2 * idx, start, mid, left, right);
    range b = getMinMax(2 * idx + 1, mid + 1, end, left, right);
    return {min(a.first, b.first), max(a.second, b.second)};
  }
};

int N, K;
SegmentTree *st;

void reset(){
  delete st;
}

void solve(){
  int Q, A, B;
  while (K--){
    cin >> Q >> A >> B;
    ++A;
    ++B;
    if (Q){
      range res = st->getMinMax(A, B);
      if (A <= res.first && res.second <= B)
        cout << "YES\n";
      else 
        cout << "NO\n";
    }
    else {
      st->update(A, B);
    }
  }
}

void init(){
  cin >> N >> K;
  st = new SegmentTree(N);
}

int main(){
  fastio
  int T;
  cin >> T;
  while (T--){
    init();
    solve();
    reset();
  }
  return 0;
}