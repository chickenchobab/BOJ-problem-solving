#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k,v,e,a,b,flag;
vector<int> graph[20001];
int visited[20001];

void dfs(int u){
    if(!visited[u]) visited[u]=1;

    for(int v:graph[u]){
        if(!visited[v]) {
            visited[v]=visited[u]+1;
            dfs(v);
        }
        else if(visited[u]%2==visited[v]%2){
            flag=1; return;
        }
    }
}

void bfs(int u){
    
    queue<int> q;
    visited[u]=1;
    q.push(u);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            if(!visited[u]) {
                visited[v]=visited[u]+1;
                q.push(v);
            }
            else if(visited[u]%2==visited[v]%2){
                flag=1; return;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>k;
    while(k--){
        cin>>v>>e;
        flag=0;
        for(int i=1;i<=v;i++){
            visited[i]=0;
            graph[i].clear();
        }
        for(int i=0;i<e;i++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=v;i++){
            if(!visited[i]) dfs(i);
        }
        cout<<((!flag && v!=1)? "YES\n" : "NO\n");
    }
    
}