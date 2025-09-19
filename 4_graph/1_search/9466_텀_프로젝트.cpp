#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int T;
int N;
int numMatched, visitCount;
int choice[100001], visited[100001];

void dfs(int node, int start){
  // started from the same node
  if (visited[node] >= start)
  {
    numMatched += (visitCount + 1 - visited[node]);
    return;
  }

  if (!visited[node])
  {
    visited[node] = ++ visitCount;
    dfs(choice[node], start);
  }
}

int main(){
  fastio

  cin >> T;

  while (T--)
  {
    cin >> N;
    for (int i = 1; i <= N; i ++){
      cin >> choice[i];
      visited[i] = 0;
    }
    numMatched = visitCount = 0;

    for (int i = 1; i <= N; i ++)
    {
      if (visited[i]) continue;

      dfs(i, visitCount + 1);
    }

    cout << N - numMatched << '\n';
  }
}