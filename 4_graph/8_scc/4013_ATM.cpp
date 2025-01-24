#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using edge = pair<int, int>;

int N, M, S, P;
vector<int> graph[500001];
int balance[500001];
bool hasRestaurant[500001];

int idx;
stack<int> s;
int indice[500001];

vector<int> totalBalance;
vector<bool> haveRestaurant;
vector<int> unitGraph[500001];
int inDegree[500001];

int topoSort(){
  queue<int> q;
  vector<bool> fromStart(totalBalance.size(), 0);
  vector<int> dp(totalBalance.size(), 0);

  for (int i = 1; i < totalBalance.size(); ++i)
    if (!inDegree[i])
      q.push(i);
  
  fromStart[indice[S]] = 1;
  dp[indice[S]] = totalBalance[indice[S]];

  while (!q.empty()){
    int cur = q.front();
    q.pop();

    for (int nxt : unitGraph[cur]){
      if (--inDegree[nxt] == 0){
        q.push(nxt);
      }
      if (fromStart[cur]){
        fromStart[nxt] = 1;
        dp[nxt] = max(dp[nxt], dp[cur] + totalBalance[nxt]);
      }
    }
  }

  int ret = 0;
  for (int i = 1; i < totalBalance.size(); ++i)
    if (haveRestaurant[i])
      ret = max(ret, dp[i]);

  return ret;
}

void mergeNodes(){
  for (int i = 1; i <= N; ++i){
    for (int j : graph[i]){
      if (indice[i] == indice[j]) continue;

      unitGraph[indice[i]].push_back(indice[j]);
      ++inDegree[indice[j]];
    }
  }
}

int dfs(int cur){
  int parent = ++idx;
  indice[cur] = -parent;
  s.push(cur);

  for (int nxt : graph[cur]){
    if (!indice[nxt])
      parent = min(parent, dfs(nxt));
    else if (indice[nxt] < 0)
      parent = min(parent, -indice[nxt]);
  }

  if (parent == -indice[cur]){
    int total = 0;
    bool restaurant = 0;
    int node;
    do {  
      node = s.top();
      s.pop();
      indice[node] = totalBalance.size();

      total += balance[node];
      if (hasRestaurant[node])
        restaurant = 1;
    }while (node != cur);

    totalBalance.push_back(total);
    haveRestaurant.push_back(restaurant);
  }

  return parent;
}

void findScc(){
  for (int i = 1; i <= N; ++i)
    if (!indice[i])
      dfs(i);
}

void init(){
  cin >> N >> M;
  int a, b;
  while (M--){
    cin >> a >> b;
    graph[a].push_back(b);
  }
  for (int i = 1; i <= N; ++i)
    cin >> balance[i];
  cin >> S >> P;
  int r;
  while (P--){
    cin >> r;
    hasRestaurant[r] = 1;
  }
  totalBalance.reserve(500001);
  totalBalance.push_back(0);
  haveRestaurant.reserve(500001);
  haveRestaurant.push_back(0);
}

int main(){
  fastio
  init();
  findScc();
  mergeNodes();
  cout << topoSort();
  return 0;
}