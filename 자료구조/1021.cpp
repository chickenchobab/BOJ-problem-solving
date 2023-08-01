#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n,m,a=0,b=0,sum=0,tmp; cin>>n>>m;
    queue<int> q;

    for(int i=1;i<=n;i++){
        q.push(i);
    }
        
    for(int i=0;i<m;i++){
        a=0;b=0;
        cin>>tmp;
        while(tmp!=q.front()){
            q.push(q.front());
            q.pop(); a++;
        }
        if(tmp==q.front()) {
            b=q.size()-a;
            sum+=min(a,b);
            q.pop();
        }
    }
    cout<<sum;
}