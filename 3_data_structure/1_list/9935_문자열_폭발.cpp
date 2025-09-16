#include <iostream>
// #include <algorithm>
// #include <vector>
#include <string>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

string S;
string bomb;

bool hasBomb(string& answer)
{
  if (answer.size() < bomb.size()) return false;

  int j = 0;
  for (int i = answer.size() - bomb.size(); i < answer.size(); ++i, ++j)
  {
    if (answer[i] != bomb[j]) return false;
  }

  return true;
}

int main()
{
  fastio

  cin >> S >> bomb;

  string answer;

  for (int i = 0; i < S.size(); ++i)
  {
    char c = S[i];
    answer.push_back(c);

    if (hasBomb(answer))
    {
      for (int i = 0; i < bomb.size(); ++i)
      {
        answer.pop_back();
      }
    }
  }

  answer.empty() ? cout << "FRULA" : cout << answer;
  
  return 0;
}