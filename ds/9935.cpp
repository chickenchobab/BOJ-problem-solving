#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int i,j;
string str, bomb;
stack<char> st;

void solve(){
    j = i + 1;
    int idx = 1;
    for (j; j<str.length(); j++){
        if (str[j] != bomb[idx]){
            //printf("%c(%d) -> %c(%d)\n", str[i], i, str[j], j);
            st.push(str[j]);
            i = j;
            return;
        }
        if (str[j] == bomb[idx]) {
            idx ++;
            st.push(str[j]);
        }
        if (idx == bomb.length()){
            //printf("pop %c(%d) -> %c(%d)\n", str[i], i, str[j], j);  
            while(idx--) {
                st.pop();
            }
            i = j;
            return;
        }
    }

    i = j - 1;
}

int main(){
    cin >> str >> bomb;
    
    for (i=0; i<str.length(); i++){
        st.push(str[i]);
        while(st.size() && st.top() == bomb[0]){
            solve();
        }
    }

    if (st.size()){
        vector<char> v;
        while(st.size()){
            v.push_back(st.top());
            st.pop();
        }    
        for (int i=v.size(); i>=1; i--){
            cout << v[i-1];
        }
    }
    else{
        cout << "FRULA";
    }
    



}