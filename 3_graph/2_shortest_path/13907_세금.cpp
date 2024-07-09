#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 333333333

using namespace std;
int N, M, K, S, D;
typedef pair<int, int> edge;
vector<edge> edges[1001];
typedef struct element{
  int wgh, num, cnt;
}elm;
queue<elm> q;
int dst[1001];
vector<edge> routes;

void input(){
  fastio
  cin >> N >> M >> K >> S >> D;
  int a, b, w;
  while (M --){
    cin >> a >> b >> w;
    edges[a].push_back({w, b});
    edges[b].push_back({w, a});
  }
}

void dijkstra(){

  for (int i = 1; i <= N; ++ i)
    dst[i] = INF;

  dst[S] = 0;
  q.push({0, S, 0});

  int cur, nxt, cnt, d, wgh;
  while (q.size()){
    elm e = q.front();
    cur = e.num, cnt = e.cnt, d = e.wgh;
    q.pop();

    if (cur == D) routes.push_back({d, cnt});

    for (edge e : edges[cur]){
      nxt = e.second, wgh = e.first;
      if (dst[nxt] > d + wgh){
        dst[nxt] = d + wgh;
        q.push({dst[nxt], nxt, cnt + 1});
      }
    }
  }
}

int calculate(int p){
  int ret = INF;
  for (auto &e : routes){
    e.first += e.second * p;
    ret = min(ret, e.first);
  }
  return ret;
}

void solve(){
  dijkstra();
  
  cout << calculate(0) << '\n';

  int p;
  while (K --){
    cin >> p;
    cout << calculate(p) << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}