#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DIV (1000000007)

using namespace std;
using ll = long long;

int N;
vector<int> graph[100001];
long long numVisit[100001];
int weight[100000];

void init(){
  cin >> N;
  int a, b;
  for (int i = 1; i < N; ++i){
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < N - 1; ++i)
    cin >> weight[i];
}

ll cntSubTree(int cur, int prv){
  ll ret = 1;

  for (auto nxt : graph[cur]){
    if (nxt == prv) continue;
    int cnt = cntSubTree(nxt, cur);
    ret += cnt;
    numVisit[nxt] = ((long long)cnt * (N - cnt));
  }
  return ret;
}

void solve(){
  long long answer = 0;
  cntSubTree(1, 0);

  sort(weight, weight + N - 1);
  sort(numVisit + 2, numVisit + N + 1, greater<ll>());

  for (int i = 0; i < N - 1; ++i)
    answer = (answer + weight[i] * numVisit[i + 2]) % DIV;

  cout << answer;
}

int main(){
  fastio
  init();
  solve();
  return 0;
}