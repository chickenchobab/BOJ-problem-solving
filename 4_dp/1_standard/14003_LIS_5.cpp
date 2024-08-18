#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
int A[1000001];
vector<int> backs; // backs of subsequences
int index[1000001];

void input(){
  fastio
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
}

void print(){
  int idx = backs.size() - 1;
  vector<int> lis;
  for (int i = N; i >= 1; --i){
    if (index[i] == idx){
      lis.push_back(A[i]);
      idx--;
    }
  }
  for (int i = lis.size() - 1; i >= 0; i--) 
    cout << lis[i] << ' ';
}

void solve(){
  index[1] = 0;
  backs.push_back(A[1]);

  for (int i = 2; i <= N; ++i){
    if (A[i] > backs.back()){
      index[i] = backs.size();
      backs.push_back(A[i]);
    }
    else {
      // minimize backs of subsequences -> maximize lengths of subsequences
      index[i] = lower_bound(backs.begin(), backs.end(), A[i]) - backs.begin();
      backs[index[i]] = A[i];
    }
  }

  cout << backs.size() << '\n';
  print();
}

int main(){
  input();
  solve();
  return 0;
}