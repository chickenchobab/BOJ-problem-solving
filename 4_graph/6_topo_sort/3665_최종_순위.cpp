#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int n, m;
// int t[501];
int ranking[501];
// vector<int> graph[501];
int inDegree[501];

// void topoSort(){
//   queue<int> q;
//   vector<int> sequence;

//   for (int i = 1; i <= n; ++i){
//     if (inDegree[i]) continue;
//     q.push(i);
//   }

//   while (!q.empty()){
//     if (q.size() > 1){
//       cout << "?";
//       return;
//     }

//     int cur = q.front();
//     sequence.push_back(cur);
//     q.pop();

//     for (int nxt : graph[cur]){
//       if (--inDegree[nxt] == 0)
//         q.push(nxt);
//     }
//   }

//   if (sequence.size() != n){
//     cout << "IMPOSSIBLE";
//     return;
//   }
//   for (int num : sequence)
//     cout << num << ' ';
// }

// bool inOrder(int a, int b){
//   return find(begin(graph[b]), end(graph[b]), a) == end(graph[b]);
// }

// void completeGraph(){
//   for (int i = 1; i <= n; ++i)
//     for (int j = 1; j < ranking[i]; ++j)
//       if (inOrder(t[j], i))
//         graph[t[j]].push_back(i);
// }

void solve(){

  // completeGraph();
  // topoSort();

  // 모든 상대적 정보가 주어졌다면 ?는 불가능하며
  // indegree가 01234임을 이용함
  vector<int> visited(n + 1, 0);
  bool flag = 1;

  for (int i = 1; i <= n; ++i){
    if (!visited[inDegree[i]])
      visited[inDegree[i]] = i;
    else {
      flag = 0;
      break;
    }
  }

  if (flag)
    for (int i = 0; i < n; ++i)
      cout << visited[i] << ' ';
  else 
    cout << "IMPOSSIBLE";
  cout << '\n';
}

void init(){
  cin >> n;
  int num;
  for (int r = 1; r <= n; ++r){
    cin >> num;
    ranking[num] = r;
    inDegree[num] = r - 1;
  }
  // for (int i = 1; i <= n; ++i){
  //   graph[i].clear();
  //   inDegree[i] = 0;
  // }
  cin >> m;
  int a, b;
  while (m--){
    cin >> a >> b;
    if (ranking[a] < ranking[b]){
      // graph[b].push_back(a);
      --inDegree[b];
      ++inDegree[a];
    }
    else {
      // graph[a].push_back(b);
      --inDegree[a];
      ++inDegree[b];
    }
  }
}

int main(){
  fastio
  int T;
  cin >> T;
  while (T--){
    init();
    solve();
  }
  return 0;
}