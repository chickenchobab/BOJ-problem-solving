#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 1000001
using namespace std;

int n, m, k;
typedef pair<int, int> p;
vector<p> edges[1001];
priority_queue<p, vector<p>, greater<p>> pq;
priority_queue<int> dst[1001];

void input(){
  fastio
  cin >> n >> m >> k;
  int a, b, c;
  for (int i = 0; i < m; ++ i){
    cin >> a >> b >> c;
    edges[a].push_back({c, b});
  }
}

void dijkstra(){

  dst[1].push(0);
  pq.push({0, 1});

  while (pq.size()){
    p cur = pq.top();
    pq.pop();

    for (p nxt : edges[cur.second]){
      int d = cur.first + nxt.first;
      if (dst[nxt.second].size() < k){
        dst[nxt.second].push(d);
        pq.push({d, nxt.second});
      }
      else if (dst[nxt.second].top() > d){
        dst[nxt.second].pop();
        dst[nxt.second].push(d);
        pq.push({d, nxt.second});
      }
    }
  }
}

void solve(){

  dijkstra();

  for (int i = 1; i <= n; ++ i){
    if (dst[i].size() < k) {
      cout << -1 << '\n';
      continue;
    }
    cout << dst[i].top() << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}