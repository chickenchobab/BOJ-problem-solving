#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int choice[101];
bool bVisited[101];
bool bInCycle[101];

bool dfs(int cur, int started)
{
  bVisited[cur] = 1;

  if (choice[cur] == started)
  {
      return true;
  }
    
  if (!bVisited[choice[cur]])
  {
      return dfs(choice[cur], started);
  }

  return false;
}

void reset()
{
  for (int i = 1; i <= N; ++i)
  {
    bVisited[i] = 0;
  }
}

int main()
{
  fastio

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> choice[i];
  }
    
  int num = 0;
  
  for (int i = 1; i <= N; ++i)
  {
    if (dfs(i, i)) // cneck this node only
    {
      bInCycle[i] = 1;
      ++num;   
    } 
    reset();
  }
    
  cout << num << '\n';
  for (int i = 1; i <= N; ++i)
  {
    if (bInCycle[i])
    {
      cout << i << '\n';
    }
  }

  return 0;
}