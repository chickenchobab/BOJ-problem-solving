#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int popul[11];
vector<int> graph[11];
bool isMine[11];
int answer, total;

void input(){
  cin >> N;
  for (int i = 1; i <= N; ++i){
    cin >> popul[i];
    total += popul[i];
  }
  int degree, cur, nxt;
  for (cur = 1; cur <= N; ++cur){
    cin >> degree;
    while (degree--){
      cin >> nxt;
      graph[cur].push_back(nxt);
    }
  }
}

bool isConnected(vector<int> &v, bool flag){

  queue<int> q;
  vector<bool> connected(N + 1, 0);
  int cnt = 0;

  for (int start = 1; start <= N; ++start){
    if (isMine[start] == flag) {
      ++cnt;
      connected[start] = 1;
      q.push(start);
      break;
    }
  }

  while (q.size()){
    int cur = q.front();
    q.pop();

    for (const int &nxt : graph[cur]){
      if (isMine[nxt] != flag || connected[nxt]) continue;
      ++cnt;
      connected[nxt] = 1;
      q.push(nxt);
    }
  }

  return cnt == v.size();
}

bool isWellDivided(){
  vector<int> mine, others;
  for (int i = 1; i <= N; ++i){
    if (!isMine[i]) others.push_back(i);
    else mine.push_back(i);
  }
  if (mine.empty() || others.empty()) return false;
  return (isConnected(mine, 1) && isConnected(others, 0));
}

void gerrymander(int cur, int sum){
  if (isWellDivided()){
    answer = min(answer, abs(total - 2 * sum));
  }

  for (int nxt = cur; nxt <= N; ++nxt){
    if (isMine[nxt]) continue;
    isMine[nxt] = 1;
    gerrymander(nxt, sum + popul[nxt]);
    isMine[nxt] = 0;
  }
}

void solve(){
  answer = total;

  for (int start = 1; start <= N; ++start){
    isMine[start] = 1;
    gerrymander(start, popul[start]);
    isMine[start] = 0;
  }

  cout << (answer != total ? answer : -1);
}

int main(){
  fastio
  input();
  solve();
  return 0;
}