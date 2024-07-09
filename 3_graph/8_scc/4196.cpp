#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int t,n,m,x,y,idx,cnt;

vector<int> graph[100001];

int into[100001], pushed[100001], popped[100001];
stack<int> s;

//사이클 때문에 생기는 진입차수를 제거
//사이클을 하나의 노드처럼 연산

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
        while(1){
            int tmp=s.top();
            s.pop();
            popped[tmp]=1;
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
        idx=cnt=0;
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
