#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, C;
vector<int> weights;
vector<int> l, r;

void init(){
  cin >> N >> C;
  weights.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> weights[i];
}

void calcAllWeights(int s, int e, int sum, vector<int>& sums){
  if (s >= e || sum >= C){
    sums.push_back(sum);
    return;
  }

  calcAllWeights(s + 1, e, sum, sums);
  if (sum + weights[s] <= C)
    calcAllWeights(s + 1, e, sum + weights[s], sums);
}

void solve(){
  int answer = 0;

  calcAllWeights(0, N / 2, 0, l);
  calcAllWeights(N / 2, N, 0, r);
  
  sort(begin(l), end(l));
  sort(begin(r), end(r)); 

  for (int i = 0; i < l.size(); ++i)
    answer += upper_bound(begin(r), end(r), C - l[i]) - begin(r);

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}