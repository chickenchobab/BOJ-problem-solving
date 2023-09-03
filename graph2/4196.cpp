#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int t,n,m,x,y,idx,cnt,si;

vector<int> graph[100001];

int into[100001], pushed[100001], popped[100001];
stack<int> s;

int dfs(int u){
    pushed[u]=++idx;
    s.push(u);

    int parent=pushed[u];
    for(int v:graph[u]){
        if(!pushed[v]) {
            parent=min(parent, dfs(v));
            into[v]--;
        }
        else if(!popped[v]) {
            parent = min(parent, pushed[v]);
            into[v]--;
        }
    }

    if(pushed[u]==parent){
        int d=1;
        ++si;
        while(1){
            int tmp=s.top();
            s.pop();
            popped[tmp]=si;
            if(into[tmp]) d=0;
            if(tmp==u) break;
        }
        if(d) cnt++;
    }
    return parent;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        si=idx=cnt=0;
        for(int i=1;i<=n;i++){
            graph[i].clear();
            into[i]=pushed[i]=popped[i]=0;
        }

        for(int i=1;i<=m;i++){
            cin>>x>>y;
            graph[x].push_back(y);
            into[y]++; 
        }
        
        for(int i=1;i<=n;i++){
            if(!pushed[i]) {dfs(i);}
        }
        
        cout<<cnt<<'\n';

    }

}
