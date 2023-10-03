#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstdio>

using namespace std;

typedef pair<int,int> p;
int n,m,map[1001][1001];
int visited[1001][1001], di[]={1,-1,0,0}, dj[]={0,0,1,-1};
queue<pair<int,int>> q;

void bfs(){
    q.push({1,1});
    visited[1][1]=1;  
    //visited[n][m]=1000001;
    while(!q.empty()){
        p tmp=q.front();
        q.pop();
        int i=tmp.first, j=tmp.second;
        for(int d=0;d<4;d++){
            int ni=i+di[d], nj=j+dj[d];
            if(ni>n || ni<1 || nj>m || nj<1) continue;
            if(map[ni][nj] || visited[ni][nj]) continue;
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

    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);
        for(int j=1;j<=m;j++){
            int tmp=str[j-1]-'0';
            map[i][j]=tmp;
            visited[i][j]=0;
        }
    }

    bfs();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%3d",visited[i][j]);
        }
        cout<<endl;
    }


    return 0;
}