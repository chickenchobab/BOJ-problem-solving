#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <iomanip>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
string expression;
double operand[26];

void init(){
  cin >> N;
  cin >> expression;
  for (int i = 0; i < N; ++i)
    cin >> operand[i];
}

double calculate(double a, double b, char ch){
  if (ch == '+') return a + b;
  if (ch == '-') return a - b;
  if (ch == '*') return a * b;
  return a / b;
}

void solve(){
  stack<double> st;
  for (char ch : expression){
    if (isalpha(ch)) 
      st.push(operand[ch - 'A']);
    else {
      auto b = st.top();
      st.pop();
      auto a = st.top();
      st.pop();

      st.push(calculate(a, b, ch));
    }
  }
  // cout.precision(2);
  cout << fixed << setprecision(2) << st.top();
}

int main(){
  fastio
  init();
  solve();
  return 0;
}