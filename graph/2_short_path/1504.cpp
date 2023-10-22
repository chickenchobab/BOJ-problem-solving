#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define INF 1000000

using namespace std;

typedef pair<int, int> edge;
int n,e,a,b,c,x,y;
vector<edge> graph[808];
priority_queue<edge, vector<edge>, greater<edge>> pq;
int d[808];

int main(){

    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }
    cin>>x>>y;

    for(int i=1;i<=n;i++){
        d[i]=(i==1? 0 : INF); 
        pq.push({d[i], i});
    }

    while(!pq.empty()){
        edge u=pq.top();
        pq.pop();
        for(edge v:graph[u.second]){
            if(d[u.second]+v.first<d[v.second]){
                d[v.second]=d[u.second]+v.first;
                pq.push({d[v.second], v.second});
            }
        }
    }

    int ans;
    if(d[x]==INF || d[y]==INF) ans=-1;
    
}