#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,map[10][10];

typedef pair<int, int> p;
int ans, di[]={1,-1,0,0}, dj[]={0,0,1,-1}, visited[10][10];

void show(){
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++){
            cout<<visited[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void bfs(){
    int i,j;
    queue<p> q;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            visited[i][j]=0;
            if(map[i][j]==2) {
                q.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    
    while(!q.empty()){
        p tmp = q.front();
        q.pop();
        i = tmp.first, j= tmp.second;
        for(int d=0; d<4; d++){
            int ni=i+di[d], nj=j+dj[d];
            if(ni<1 || nj<1 || ni>n || nj>m) continue;
            if(visited[ni][nj] || map[ni][nj]) continue;
            q.push({ni,nj});
            visited[ni][nj]=1;  
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(visited[i][j]==0) cnt++;
        }
    }
    ans=max(ans,cnt);
    // show();
    // cout<<endl;
}

void build(int cur){
    if(cur==3) {
		bfs();
		return;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(map[i][j]==0) {
				map[i][j] = 1;
				build(cur+1);
				map[i][j] = 0;
			}
		}
	}
}

int main(){
    cin>>n>>m;
    fill(&map[0][0], &map[9][9], 1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]==0){
                map[i][j]=1;
				build(1);         
                map[i][j]=0;
            }
        }
    }

    cout<<ans;

}