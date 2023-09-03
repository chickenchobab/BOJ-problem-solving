#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,a,b;
int into[32001];
vector<int> graph[32001];
queue<int> q;

void toposort(){

    for(int i=1;i<=n;i++){
        if(!into[i]) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<' ';
        for(int v:graph[u]){
            if(--into[v]==0) q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        into[b]++;
    }
    toposort();
    
}