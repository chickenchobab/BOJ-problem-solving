#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,r;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int u)
{
    visited[u]=1;
    cout<<u<<' ';

    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!visited[v])
            dfs(graph, visited, v);
    }
}

void bfs(vector<vector<int>>& graph, vector<int>& visited, int u)
{
    queue<int> q;
    q.push(u); visited[u]=1; cout<<u<<' ';

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(!visited[v]){
                q.push(v); visited[v]=1; cout<<v<<' ';
            }
        }
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>r;
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1,0);

    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, visited,r);
    
    cout<<'\n';
    for(int i=1;i<=n;i++)   visited[i]=0;

    bfs(graph,visited,r);

}