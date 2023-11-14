#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n,e,a,b,c,ans;
typedef tuple<int, int, int> tp;
priority_queue<tp, vector<tp>, greater<tp>> pq;
int parent[10001];

void init(){
    for(int i=1;i<=n;i++)
        parent[i]=-1;
}

int find(int x){
    if(parent[x]<0) return x;
    else return parent[x]=find(parent[x]);
}

void merge(int a, int b){
    a=find(a);
    b=find(b);
    if(parent[a]<parent[b])
        parent[b]=a;
    else{
        if(parent[a]==parent[b])
            parent[b]--;
        parent[a]=b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>e;

    init();

    for(int i=1;i<=e;i++){
        cin>>a>>b>>c;
        pq.push({c,a,b});
    }

    while(pq.size()){
        tp u=pq.top();
        pq.pop();
        int a=get<1>(u);
        int b=get<2>(u);
        int c=get<0>(u);
        if(find(a)==find(b)) continue;
        merge(a,b);
        ans+=c;
    }

    cout<<ans;
}