#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,a,b;

int ind[3333], visited[3333];
vector<int> graph[3333];
queue<int> q;

int main(){
    cin>>n;
    int t=3;

    while(t--){

        cin>>a;
        q.push(a);
        for(int i=2;i<=n;i++){
            cin>>b;
            graph[a].push_back(b);
            ind[b]++;
            a=b;
        }

    }
    
    while(!q.empty()){
            int u=q.front();
            q.pop();
            if(ind[u]==0)
            cout<<u<<' ';
            for(int v:graph[u]){
                ind[v]--;
                if(visited[v]==0) {
                    q.push(v);
                    visited[v]=1;
                }
            }
        }

}