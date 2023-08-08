#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,r,cnt=0;

void bfs(vector<vector<int>>& graph, vector<int>& visited, int& r){
    queue<int> q;
    visited[r]=++cnt;
    q.push(r);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(!visited[v]){
                visited[v]=++cnt;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>r;
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1,0);
    
    
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    bfs(graph, visited, r);
    
    for(int i=1;i<=n;i++){
        cout<<visited[i]<<'\n';
    }

    return 0;
}
