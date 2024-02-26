#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,a,b;

vector<int> graph[33333];
int ind[33333];
queue<int> q;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        ind[b]++;
    }

    //topological
    for(int i=1;i<=n;i++){
        if(!ind[i]) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<' ';
        for(int v:graph[u]){
            if(--ind[v]==0) {
                q.push(v);
            }
        }
    }

    return 0;
}