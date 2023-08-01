#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n,k; cin>>n>>k;

    for(int i=1;i<=n; i++) 
        q.push(i);
    
    cout<<'<';
    while(!q.empty()){
        for(int i=1;i<=k;i++){
            int front = q.front();
            q.pop();
            if(i==k) cout<<front; 
            else q.push(front);
        }
        if(!q.empty()) cout<<", ";
    }
    cout<<'>';
    return 0;

}