#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
#include <cstdio>

using namespace std;

int n,m,ans;
int map[1001][1001], visited[1001][1001];
int di[]={1,-1,0,0}, dj[]={0,0,1,-1};
queue<pair<int,int>> q;

void bfs(int i, int j){

    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        pair<int, int> tmp=q.front();
        int i=tmp.first;
        int j=tmp.second;
        q.pop();
        for(int s=0;s<4;s++){
            int ni=i+di[s];
            int nj=j+dj[s];
            if(ni<1 || nj<1 || ni>n || nj>m) continue;
            if(map[ni][nj]==1) continue;
            visited[ni][nj]=visited[i][j]+1;
            q.push({ni,nj});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m; 
    cin.ignore();
    ans=n*m+1;

    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);
        for(int j=1;j<=m;j++){
            int tmp=str[j-1]-'0';
            map[i][j]=tmp;
            visited[i][j]=0;
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(map[i][j]==1){
    //             bfs(i,j);
    //             if(visited[n][m] && visited[1][1])
    //                 ans=min(ans,visited[n][m]+visited[1][1]-2);
    //         }
    //     }
    // }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%3d",map[i][j]);
    //     }
    //     cout<<endl;
    // }

    bfs(1,1);
    cout<<(ans==n*m+1? -1: ans);
    
}