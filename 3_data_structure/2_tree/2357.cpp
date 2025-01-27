#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000000001
#define MIN 0
using namespace std;

class SegmentTree{
public:
  int size;
  vector<int> mins, maxes;

  SegmentTree(int n){
    for (size = 1; size <= n; size *= 2);
    mins.assign(size * 2, MAX);
    maxes.assign(size * 2, MIN);
  }

  void update(int pos, int val){
    int idx = size + pos - 1;

    mins[idx] = maxes[idx] = val;
    idx /= 2;

    while (idx){
      mins[idx] = min(mins[idx * 2], mins[idx * 2 + 1]);
      maxes[idx] = max(maxes[idx * 2], maxes[idx * 2 + 1]);
      idx /= 2;
    }
  }

  int findMin(int left, int right){
    return findMin(1, 1, size, left, right);
  }

  int findMax(int left, int right){
    return findMax(1, 1, size, left, right);
  }

  // Check subtree at idx on which start and end depend.
  int findMin(int idx, int start, int end, int left, int right){
    if (right < start || end < left)
      return MAX;
    if (left <= start && end <= right)
      return mins[idx];
    int mid = (start + end) / 2;
    int a = findMin(2 * idx, start, mid, left, right);
    int b = findMin(2 * idx + 1, mid + 1, end, left, right);
    return min(a, b);
  }

  int findMax(int idx, int start, int end, int left, int right){
    if (right < start || end < left)
      return MIN;
    if (left <= start && end <= right)
      return maxes[idx];
    int mid = (start + end) / 2;
    int a = findMax(2 * idx, start, mid, left, right);
    int b = findMax(2 * idx + 1, mid + 1, end, left, right);
    return max(a, b);
  }
};

int N, M;
SegmentTree st(100000);

void processQueries(){
  int a, b;
  while (M--){
    cin >> a >> b;
    cout << st.findMin(a, b) << ' ' << st.findMax(a, b) << '\n';
  }
}

void init(){
  cin >> N >> M;
  int num;
  for (int i = 1; i <= N; ++i){
    cin >> num;
    st.update(i, num);
  }
}

int main(){
  fastio
  init();
  processQueries();
  return 0;
}