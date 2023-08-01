#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cal(int ch){
    if(ch=='C') return 12;
    if(ch=='H') return 1;
    if(ch=='O') return 16;
    return ch;
}

int main(){

    int tmp,sum=0;
    string str;
    getline(cin, str);

    stack<int> st;

    for(int i=0;i<str.length();i++){
        char ch=str[i];

        if(ch>='2' && ch<='9')
        {   
            int mul=ch-'0';
            tmp=st.top()*mul;
            st.pop(); st.push(tmp); 
        }
        else if(ch==')'){
            tmp=0;
            while(1){
                if(st.top()=='(') {
                    st.pop(); st.push(tmp);
                    break;
                }
                tmp+=st.top();
                st.pop();
            }
        }
        else {
            st.push(cal(ch));
        }
    }
    
    while(!st.empty()){
        sum+=st.top();
        st.pop();
    }

    cout<<sum;
    return 0;
}