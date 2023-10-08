#include <iostream>
#include <algorithm>
#include <queue>

#define INF 3333333

using namespace std;

int v,e,s,a,b;
int dis[20001][20001],d[20001],c[20001];

int closest(){
    int mn=INF;
    int idx=0;
    for(int i=1;i<=v;i++){
        if(c[i]) continue;
        if(d[i]<mn){
            mn=d[i];
            idx=i;
        }
    }
    return idx;
}

int main(){
    cin>>v>>e>>s;

    fill(&dis[1][1], &dis[v][v], INF);

    for(int i=1;i<=e;i++){
        cin>>a>>b;
        cin>>dis[a][b];
    }
    for(int i=1;i<=v;i++){
        d[i]=dis[s][i];
    }
    
    // for(int i=1;i<=v;i++){
    //     cout<<d[i]<<' ';
    // }
    // cout<<endl;

    c[s]=1, d[s]=0;
    while(1){
        int u=closest();
        if(u==0) break;
        c[u]=1;
        for(int i=1;i<=v;i++){
            if(c[i]) continue;
            if(d[i]>d[u]+dis[u][i]){
                d[i]=d[u]+dis[u][i];
            }
        }
    }

    for(int i=1;i<=v;i++){
        if(d[i]==INF) cout<<"INF";
        else cout<<d[i];
        cout<<'\n';
    }

}