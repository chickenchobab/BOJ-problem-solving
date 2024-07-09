#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 500000
using namespace std;

int n;
typedef pair<int, int> p;
stack<p> st;

void input(){
    fastio
    cin >> n;
}

void solve(){
    int num;
    for (int i = 1; i <= n; i ++){
        cin >> num;
        while (st.size() && st.top().second < num){
            st.pop();
        }
        if (st.size()) cout << st.top().first << ' ';
        else cout << 0 << ' ';
        st.push({i, num});
    }
}

int main(){
    input();
    solve();
    return 0;
}