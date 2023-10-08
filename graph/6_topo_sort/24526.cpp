#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,a,b;
vector<int> graph[100001];

int dp[100001], ind[100001], visited[100001];
int ans;

int dfs(int u){
    visited[u]=1;
    for(int v: graph[u]){
        if(visited[v]) continue;
        if(--ind[v]) continue;
        return dp[v]=dp[u]+dfs(v);  
    }
    if(ind[u]==0) return 1;
    return 0;
}

int main(){
    cin>>n>>m;

    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        ind[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!ind[i] && !visited[i]) {
            dfs(i);
        }
    }

    sort(dp+1, dp+n+1);
    cout<<dp[n];

}