#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstdio>

using namespace std;

int n,m,map[1001][1001];
queue<pair<int,int>> q;

void bfs(){
    int di[]={0,1,0,-1};
    int dj[]={1,0,-1,0};
    int chance=1;
    
    q.push({1,1});
    map[1][1]=1;

    while(!q.empty()){
        int i,j;
        tie(i,j)=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nii=i+2*di[k];
            int nj=j+dj[k];
            int njj=j+2*dj[k];
            if(ni>n || ni<1 || nj>m || nj<1) continue;
            if(map[ni][nj]>0) continue;
            else if(map[ni][nj]<0 && chance){
                if(nii<=n && nii>=1 && njj<=m && njj>=1){
                    if(map[nii][njj]==0){
                        ni=nii, nj=njj; chance=0;
                    }
                }
            }
            
         
    
                map[ni][nj]=map[i][j]+1;
                q.push({ni,nj});
        }
            
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m; cin.ignore();
    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);
        for(int j=1;j<=m;j++){
            int tmp=str[j-1]-'0';
            map[i][j]=(tmp? -tmp: 0);
        }
    }

    bfs();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%3d",map[i][j]);
        }
        cout<<endl;
    }

    cout<<(map[n][m]? map[n][m]: -1);
    
}