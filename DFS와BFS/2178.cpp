#include <iostream>
#include <string>
#include <queue>
#include <tuple>


using namespace std;

int n,m,map[101][101];
queue<pair<int, int>> q;

void bfs(int i, int j){

    int di[]={0,0,1,-1};
    int dj[]={1,-1,0,0};

    q.push({i,j}); 
    map[i][j]=1;
    
    while(!q.empty()){
        tie(i,j)=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>n || ni<1 || nj>m || nj<1) continue;
            if(!map[ni][nj]){
                q.push({ni,nj}); 
                map[ni][nj]=map[i][j]+1;
                if(ni==n && nj==m) return;
            }
        } 
    }
}

int main(){
    ios::sync_with_stdio(false);

    cin>>n>>m; cin.ignore();

    for(int i=1;i<=n;i++){
        string str;
        getline(cin, str);
        for(int j=1;j<=m;j++){
            int tmp = str[j-1]-'0';
            map[i][j]=(tmp? 0: -1);
        }
    }

    bfs(1,1);

    cout<<map[n][m];
}