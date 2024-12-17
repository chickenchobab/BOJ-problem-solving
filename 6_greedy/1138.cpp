#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int numTaller[11];

void init(){
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> numTaller[i];
}

void solve(){
  vector<int> vec;
  vec.push_back(N);

  for (int i = N - 1; i >= 1; --i){
    if (vec.size() == numTaller[i])
      vec.push_back(i);
    else 
      vec.insert(begin(vec) + numTaller[i], i);
  }
  
  for (int num : vec)
    cout << num << ' ';
}

int main(){
  fastio
  init();
  solve();
  return 0;
}