#include <iostream>
#include <queue>

using namespace std;

int n,k,cnt=0,map[100001]={0,};

void bfs(int x){
    queue<int> q;
    q.push(x); map[x]=1;

    while(!q.empty()){
        x=q.front();
        q.pop();
        
        for(int nx:{x-1, x+1, 2*x}){
            if(nx>100000 || nx<0) continue;
            if(map[nx]) continue;

            q.push(nx); map[nx]=map[x]+1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    bfs(n);
    cout<<map[k]-1;
}