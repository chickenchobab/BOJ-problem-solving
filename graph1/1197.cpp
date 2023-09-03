#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> p;

long long cnt;
int v,e,a,b,c;
vector<p> g[10001];
priority_queue<p, vector<p>, greater<p>> pq;
int visited[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>v>>e;

    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        g[a].push_back({c,b});
        g[b].push_back({c,a});
    }

    pq.push({0,a});
    while(!pq.empty()){
        p cur=pq.top();
        int d=cur.first;
        int nxt=cur.second;
        pq.pop();

        if(visited[nxt]) continue;
        visited[nxt]=1;
        cnt+=d;
        
        for(int i=0;i<g[nxt].size();i++){
            if(visited[g[nxt][i].second]) continue;
            pq.push(g[nxt][i]);
        }
    }

    cout<<cnt;

}