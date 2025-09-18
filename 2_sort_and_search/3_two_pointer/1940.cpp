#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
vector<int> material;

void init(){
  cin >> N >> M;
  material.resize(N);
  for (int i = 0; i < N; ++i)
    cin >> material[i];
}

void solve(){
  int answer = 0;

  sort(begin(material), end(material));
  
  int s = 0, e = N - 1;
  while (s < e){
    int tmp = material[s] + material[e];
    if (tmp > M)
      --e;
    else if (tmp < M)
      ++s;
    else {
      ++answer;
      --e;
      ++s;
    }
  }
  
  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}