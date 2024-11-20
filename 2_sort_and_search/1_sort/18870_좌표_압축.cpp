#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
vector<pair<int, int>> points;

void input(){
  cin >> N;
  int p;
  for (int i = 0; i < N; ++i){
    cin >> p;
    points.push_back({p, i});
  }
}

void solve(){
  vector<int> counts(N, 0);
  sort(points.begin(), points.end());

  int cnt = 1;
  for (int i = 1; i < points.size(); ++i){
    if (points[i].first == points[i - 1].first)
      counts[points[i].second] = counts[points[i - 1].second];
    else 
      counts[points[i].second] = cnt++;
  }

  for (int i = 0; i < N; ++i)
    cout << counts[i] << ' ';
}

int main(){
  fastio
  input();
  solve();
  return 0;
}