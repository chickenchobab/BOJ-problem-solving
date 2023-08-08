#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n,m,r,cnt=0;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int& r)
{
    stack<int> st;
    visited[r]=++cnt;
    st.push(r);
    while(!st.empty()){
        
        int u=st.top();
        int found=0;
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(!visited[v]){
                found=1; 
                visited[v]=++cnt; 
                st.push(v);
                break;
            }
        }
        if(!found) st.pop();
    }
}

int main(){

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
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, visited, r);

    for(int i=1;i<=n;i++){
        cout<<visited[i]<<'\n';
    }
}
