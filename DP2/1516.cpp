#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, tmp;
int into[501], time[501], dp[501];
vector<int> graph[501];

void toposort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!into[i]) {
            q.push(i);
        }
        dp[i]=time[i];
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            dp[v]=max(dp[v], dp[u]+time[v]);
            if(--into[v]==0) q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>time[i];
        while(1){
            cin>>tmp;
            if(tmp==-1) break;
            graph[tmp].push_back(i);
            into[i]++;
        }
    }
    toposort();
    for(int i=1;i<=n;i++) cout<<dp[i]<<'\n';
    
}