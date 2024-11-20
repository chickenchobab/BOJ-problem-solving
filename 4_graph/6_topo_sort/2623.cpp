#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
vector<int> edges[1001];
int inDegree[1001];
queue<int> q;
vector<int> answer;

void input(){
  fastio
  cin >> N >> M;
  int num, a, b;
  while (M--){
    cin >> num;
    cin >> a;
    for (int i = 1; i < num; ++i){
      cin >> b;
      edges[a].push_back(b);
      inDegree[b]++;
      a = b;
    }
  }
}

void topoSort(){
  for (int i = 1; i <= N; ++i){
    if (!inDegree[i]) q.push(i);
  }

  while (q.size()){
    int cur = q.front();
    q.pop();
    answer.push_back(cur);

    for (int nxt : edges[cur]){
      if (--inDegree[nxt] == 0){
        q.push({nxt});
      }
    }
  }
}

void solve(){
  topoSort();
  if (answer.size() == N) {
    for (int &ans : answer)
      cout << ans << '\n';
  }
  else cout << 0;
}

int main(){
  input();
  solve();
  return 0;
}