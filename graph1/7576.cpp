#include <iostream>
#include <queue>

using namespace std;

int n,m,map[1001][1001];
queue<pair<int,int>> q;

void bfs(){
    
    int di[]={0,0,1,-1};
    int dj[]={1,-1,0,0};
    
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>n || ni<1 || nj>m || nj<1) continue;
            if(map[ni][nj]) continue;
            q.push({ni,nj});
            map[ni][nj]=map[i][j]+1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
            if(map[i][j]==1) 
                q.push({i,j});
        }
    }
    bfs();

    int max=0,flag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(max<map[i][j])
                max=map[i][j];
            if(!map[i][j])
                flag=1;
        }
    }
    cout<<(flag? -1: max-1);
    

}