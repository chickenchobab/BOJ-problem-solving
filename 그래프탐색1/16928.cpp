#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,cnt=0;
int visited[101]={0,}, teleport[101]={0,};
vector<vector<int>> v(101);

void bfs(){
    queue<int> q;
    q.push(1); visited[1]=1;
    while(!q.empty()){

        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int nxt=v[u][i];
            if(teleport[nxt]) nxt=v[nxt][0];
            if(visited[nxt]) continue;
           
            visited[nxt]=visited[u]+1;
                
            q.push(nxt);
        }
    }
}

int main(){
    cin>>n>>m;
    int t=n+m;

    int x,y;
    while(t--){
       cin>>x>>y;
       v[x].push_back(y);
       teleport[x]=1;
    }
    
    for(int i=1;i<=100;i++){
        if(!v[i].empty()) continue;
        for(int j=1;j<=6;j++){
            if(i+j>100) continue;
            v[i].push_back(i+j);
        }
    }

    bfs();

    cout<<visited[100]-1;

}