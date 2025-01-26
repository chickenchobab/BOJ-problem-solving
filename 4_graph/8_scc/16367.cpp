#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int k, n;
vector<int> graph[10001];
stack<int> s;
bool isSatisfiable;
int idx;
int indice[10001];
int numScc;
bool isRed[5001];

inline int NOT(int x){
  return x % 2 ? x + 1 : x - 1;
}

void printSolution(){
  if (!isSatisfiable){
    cout << -1;
    return;
  }
  for (int i = 1; i <= k; ++i)
    isRed[i] ? cout << 'R' : cout << 'B';
}

void findSolution(){
  vector<int> node(2 * k + 1);
  vector<bool> isSet(k + 1, 0);

  for (int i = 1; i <= 2 * k; ++i)
    node[i] = i;

  sort(begin(node) + 1, end(node), [](int a, int b){
    return indice[a] > indice[b];
  });

  for (int i = 1; i <= 2 * k; ++i){
    if (isSet[(node[i] + 1) / 2]) continue;
    isSet[(node[i] + 1) / 2] = 1;
    isRed[(node[i] + 1) / 2] = (node[i] % 2);
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
  isSatisfiable = 1;
  for (int i = 1; i <= 2 * k && isSatisfiable; ++i)
    if (!indice[i])
      dfs(i);
}

void setGraph(){
  cin >> k >> n;

  int l[3];
  char c;

  while (n--){
    for (int g = 0; g < 3; ++g){
      cin >> l[g] >> c;
      l[g] = 2 * l[g] - (c != 'R');
    }
    
    for (int g = 0; g < 3; ++g){
      graph[NOT(l[g])].push_back(l[(g + 1) % 3]);
      graph[NOT(l[(g + 1) % 3])].push_back(l[g]);
    }
    
  }
}


int main(){
  fastio
  setGraph();
  findScc();
  findSolution();
  printSolution();
  return 0;
}