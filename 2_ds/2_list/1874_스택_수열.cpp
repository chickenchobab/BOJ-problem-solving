#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int arr[100001];
stack<int> st;
string ans = "";

void input(){
    fastio
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
}

void spush(int num){
    st.push(num);
    ans += "+\n";
}

void spop(){
    st.pop();
    ans += "-\n";
}

void solve(){
    int num = 1;
    for (int i = 1; i <= n; i ++){
        while (st.empty() || st.top() < arr[i]){
            spush(num ++);
        }
        if (st.top() == arr[i]) spop();
        else {
            cout << "NO";
            return;
        }
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}