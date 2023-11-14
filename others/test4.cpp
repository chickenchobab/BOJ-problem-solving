#include <iostream>
#include <stack>

using namespace std;
stack<int> st;

int tmp;

int func(int a, int b, int input){
    st.push(tmp);
    int r=a-b;
    tmp=r;
    r+=(tmp>>31);
    r/=2;
    tmp=(r+1*b);
    if(tmp<=input){
        r=tmp;
        if(tmp>=input) {
            while(st.size() && st.top()){
                r+=st.top();
                st.pop();
            }
            return r;
        }
        else return func(a,tmp+1,input);
    }
    else{
        return func(tmp-1, b, input);
    }
}

int main(){

    int r=0,i;
    for(i=1;r!=15 && i<=14 ;i++){
        r=func(14, 0, i);
        while(!st.empty()) st.pop();
        tmp=0;
        cout<<r<<endl;
    }
    cout<<"return "<<r<<" : input "<<i-1<<endl;
}