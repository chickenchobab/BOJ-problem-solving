#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m,tmp;

    cin>>n;
    int ds[n];

    deque<int> dq;

    for(int i=0; i<n;i++) {
        cin>>ds[i];
    }
    for(int i=0; i<n;i++) {
        cin>>tmp;
        if(!ds[i]) dq.push_back(tmp); 
    }
        
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>tmp; 
        dq.push_front(tmp);
        tmp=dq.back(); 
        dq.pop_back();
        cout<<tmp<<' ';
    }
}