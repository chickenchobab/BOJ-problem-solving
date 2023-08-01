#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;

    while(t--){
        string str;
        int n,tmp,rev=0,err=0;
        deque<int> dq;

        cin>>str>>n;
        cin.ignore();

        cin.get();
        while(n--){
            cin>>tmp;
            dq.push_back(tmp);
            if(n) cin.get();
        }
        cin.get();

        for(int i=0;i<str.length();i++){
            if(str[i]=='R') {
                if(rev) rev=0;
                else    rev=1;
            }
            else{
                if(dq.empty()) {err=1; break;}
                else {
                    if(rev) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }

        if(err){
            cout<<"error"<<'\n';
        }
        else{
            cout<<'[';
            while(!dq.empty()){
                if(!rev){
                    cout<<dq.front();
                    dq.pop_front();
                }
                else{
                    cout<<dq.back();
                    dq.pop_back();
                }
                if(!dq.empty()) cout<<',';
            }
            cout<<']'<<'\n';
        }
    }
}