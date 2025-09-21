#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int G, P;
int parent[100001];

int find(int c)
{
  if (parent[c] == c) return c;
  return parent[c] = find(parent[c]);
}

int main()
{
  fastio

  cin >> G >> P;

  for (int i = 1; i <= G; ++i)
  {
    parent[i] = i;
  }

  int answer = 0;

  int gate;
  for (int i = 1; i <= P; ++i)
  {
    cin >> gate;

    gate = find(gate);
    if (!gate) break;

    parent[gate] = find(gate - 1);
    ++answer;
  }

  cout << answer;

  return 0;
}