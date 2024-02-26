#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int arr[100001];
stack<int> st;  // 스택 = 임시 공간
string ans = "";


void stack_push(int num){
    st.push(num);
    ans += "+\n";
}

void stack_pop(){
    if (st.size()) st.pop();
    ans += "-\n";
}

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
}

int main(){
    input();

    int num = 1;
    for (int i = 1; i <= n; i ++){
        while(st.empty() || st.top() < arr[i]){
            stack_push(num ++);
        }
        if (st.top() == arr[i]) stack_pop();
    }

    if (st.empty())
        cout << ans;
    else
        cout << "NO";

}