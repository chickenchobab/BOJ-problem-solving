#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> graph[20001];
stack<int> s;
int idx;
int numScc;
int indice[20001];
bool solution[10001];

inline int NOT(int n){
  return n % 2 ? n + 1 : n - 1;
}

void printAnswer(){
  cout << 1 << '\n';
  for (int i = 1; i <= N; ++i)
    cout << solution[i] << ' ';
}

void findSolution(){
  vector<int> nodes(2 * N + 1);
  vector<bool> isSet(N + 1, 0);

  for (int i = 1; i <= 2 * N; ++i)
    nodes[i] = i;
  
  sort(begin(nodes) + 1, end(nodes), [](int a, int b){
    return indice[a] > indice[b];
  });

  for (int i = 1; i <= 2 * N; ++i){
    if (!isSet[(nodes[i] + 1) / 2]){
      isSet[(nodes[i] + 1) / 2] = 1;
      solution[(nodes[i] + 1) / 2] = (nodes[i] % 2);
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
    int node;
    do {
      node = s.top();
      s.pop();
      indice[node] = numScc + 1;
      if (indice[NOT(node)] == numScc + 1){
        cout << 0;
        exit(0);
      }
    }while (node != cur);
    ++numScc;
  }

  return parent;
}

void findScc(){
  for (int i = 1; i <= 2 * N; ++i)
    if (!indice[i])
      dfs(i);
}

void setGraph(){
  cin >> N >> M;
  int a, b;
  while (M--){
    cin >> a >> b;
    a = (a > 0 ? 2 * a : -2 * a - 1);
    b = (b > 0 ? 2 * b : -2 * b - 1);
    graph[NOT(a)].push_back(b);
    graph[NOT(b)].push_back(a);
  }
}

int main(){
  fastio
  setGraph();
  findScc();
  findSolution();
  printAnswer();
  return 0;
}