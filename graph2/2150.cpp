#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int v,e,a,b,idx;
vector<int> graph[10001];
int order[10001], done[10001];
stack<int> s;
vector<vector<int>> scc;

int dfs(int x){
    order[x]=++idx;
    s.push(x);

    int parent = order[x];

    for(int y:graph[x]){
        if(!order[y]) parent=min(parent, dfs(y));
        else if(!done[y]) parent=min(parent, order[y]);
    }

    if(order[x]==parent){
        vector<int> c;
        while(1){
            int tmp=s.top();
            s.pop();
            c.push_back(tmp);
            done[tmp]=1;
            if(tmp==x) break;
        }
        sort(c.begin(),c.end());
        scc.push_back(c);
    }

    return parent;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=v;i++){
        if(!order[i]) dfs(i);
    }
    sort(scc.begin(), scc.end());
    cout<<scc.size()<<'\n';
    for(vector<int> v:scc){
        for(int tmp:v){
            cout<<tmp<<' ';
        }
        cout<<-1<<'\n';
    }
}