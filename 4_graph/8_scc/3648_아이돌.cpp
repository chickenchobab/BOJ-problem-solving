#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
vector<int> graph[2001];
int idx;
int indice[2001];
stack<int> s;
int numScc;
bool isSatisfiable;

inline int NOT(int x){
  return x % 2 ? x + 1 : x - 1;
}

void printAnswer(){
  isSatisfiable ? cout << "yes" : cout << "no";
  cout << '\n';
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

  if (parent == -indice[cur] && isSatisfiable){
    int node;
    do {
      node = s.top();
      s.pop();
      if (indice[NOT(node)] == numScc + 1){
        isSatisfiable = 0;
        return 0;
      }
      indice[node] = numScc + 1;
    } while (node != cur);
    ++numScc;
  }

  return parent;
}

void findScc(){
  for (int i = 1; i <= 2 * n && isSatisfiable; ++i)
    if (!indice[i])
      dfs(i);
}

void setGraph(){
  int a, b;
  while (m--){
    cin >> a >> b;
    a = a > 0 ? 2 * a : -2 * a - 1;
    b = b > 0 ? 2 * b : -2 * b - 1;
    graph[NOT(a)].push_back(b);
    graph[NOT(b)].push_back(a);
  }
  graph[1].push_back(2);
}

void init(){
  isSatisfiable = 1;
  for (int i = 1; i <= 2 * n; ++i){
    indice[i] = 0;
    graph[i].clear();
  }
}

int main(){
  fastio
  while (cin >> n >> m){
    init();
    setGraph();
    findScc();
    printAnswer();
  }
  return 0;
}