#include <iostream>
#include <stack>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,tmp,turn=1;
    cin>>n;
    
    stack<int> st;
    
    
    for(int i=1;i<=n;i++){
        cin>>tmp;
        st.push(tmp);
        while(!st.empty() && st.top()==turn){
            st.pop(); 
            turn++;
        } 
    }
    
    cout<< (st.empty()? "Nice" : "Sad");
    
    return 0;
}