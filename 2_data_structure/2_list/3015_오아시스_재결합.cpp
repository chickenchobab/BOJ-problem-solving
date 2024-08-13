#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int N;
stack<pair<int, int>> st;

void input(){
  fastio
  cin >> N;
}

void solve(){
  int tmp, cnt;
  long long ans = 0;

  while (N --){
    cin >> tmp;
    cnt = 1;

    while (st.size() && st.top().first < tmp){
      ans += st.top().second;
      st.pop();
    }

    if (st.size()) {
      if (st.top().first == tmp) {
        ans += (st.top().second + (st.size() > 1));
        cnt += st.top().second;
        st.pop();
      }
      else ans += 1;
    }
    st.push({tmp, cnt});
  }
  cout << ans;
}

int main(){
  input();
  solve();
  return 0;
}