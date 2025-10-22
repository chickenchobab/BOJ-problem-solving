#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

stack<char> st;
stack<string> results;

int priority(char c)
{
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/') return 2;
  return 0;
}

void calculate()
{
  if (results.size() < 2) return;

  string b = results.top();
  results.pop();
  string a = results.top();
  results.pop();

  results.push(a + b + st.top());
  st.pop();
}

int main()
{
  fastio

  while (1)
  {
    char c = cin.get();

    if (isalpha(c))
    {
      results.push(string(1, c));
    }
    else if (c == '(')
    {
      st.push(c);
    }
    else if (c == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        calculate();
      }
      
      st.pop(); // pop (
    }
    else
    {
      while (!st.empty() && priority(st.top()) >= priority(c))
      {
        calculate();
      }

      st.push(c);
    }

    if (c == '\n')
    {
      break;
    }
  }

  if (!results.empty())
  {
    cout << results.top();
  }

  return 0;
}