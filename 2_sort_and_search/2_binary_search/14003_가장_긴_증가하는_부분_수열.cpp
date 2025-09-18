#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int A[1000001];
vector<int> backs; // backs[i] : back of sequence of which the length is i + 1
int pos[1000001];
vector<int> answer;

int main()
{
  fastio

  cin >> N;
  
  cin >> A[1];
  backs.push_back(A[1]);

  for (int i = 2; i <= N; ++i)
  { 
    cin >> A[i];
    if (backs.back() < A[i])
    {
      pos[i] = backs.size();
      backs.push_back(A[i]);
    }
    else
    {
      pos[i] = lower_bound(begin(backs), end(backs), A[i]) - begin(backs);
      backs[pos[i]] = A[i];
    }
  }

  cout << backs.size() << '\n';

  int idx = backs.size() - 1;
  for (int i = N; i >= 1 && idx >= 0; --i)
  {
    if (pos[i] == idx)
    {
      answer.push_back(A[i]);
      --idx;
    }
  }

  for (auto it = rbegin(answer); it != rend(answer); ++it)
  {
    cout << *it << ' ';
  }

  return 0;
}