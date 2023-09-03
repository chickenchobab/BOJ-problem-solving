#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge;

int n,m,idx,cnt,sum;
int map[11][11], visited[11][11];
int di[]={0,0,1,-1}, dj[]={1,-1,0,0};

int set[7];
vector<edge> eg;

int find(int x){
    if(set[x]<=0) return x;
    return (set[x]=find(set[x]));
}

void unite(int a, int b){
    int c1=find(a);
    int c2=find(b);

    if(set[c1]<set[c2])
        set[c2]=c1;
    else{
        if(set[c1]==set[c2])
            set[c2]--;
        set[c1]=c2;
    }
}

void dfs(int i, int j){
    visited[i][j]=1;
    map[i][j]=idx;
    for(int s=0;s<4;s++){
        int ni=i+di[s];
        int nj=j+dj[s];
        if(ni>n || nj>m || ni<1 || nj<1) continue;
        if(map[ni][nj]!=-1 || visited[ni][nj]) continue;
        dfs(ni,nj);
    }
}

void bfs(int i, int j, int num, int d){

    int found=0;
    int dis=1;
    while(1){
        int ni=i+dis*di[d];
        int nj=j+dis*dj[d];
        if(ni>n || nj>m || ni<1 || nj<1) return;
        if(map[ni][nj]==num) return;
        if(map[ni][nj]){
            found=1;
            if(dis!=1)
                eg.push_back({dis,num,map[ni][nj]});
        }
        if(found) return;
        dis++;
    }

}

int main(){
    cin>>n>>m;
    int tmp;
    idx=1;
    fill(&visited[0][0], &visited[n][m],0);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tmp;
            map[i][j]=(tmp? -tmp: tmp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]==-1) {
                dfs(i,j);
                idx++;
            }
        }
    }
    idx--;

    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++){
            if(!map[i][j]) continue;
            for(int d=0;d<4;d++){
                int ni=i+di[d];
                int nj=j+dj[d];
                if(ni>n || nj>m || ni<1 || nj<1) continue;
                if(map[ni][nj]) continue;
                bfs(ni,nj,map[i][j],d);
            }
        }
    }

    sort(eg.begin(), eg.end());
    
    for(edge tmp:eg){
        int a=get<1>(tmp);
        int b=get<2>(tmp);
        int c=get<0>(tmp);
        
        if(find(a)==find(b)) continue;

        cout<<c<<' '<<a<<' '<<b<<'\n';
        unite(a,b);
        cnt++;
        sum+=c;
    }

    cout<<(cnt==idx-1? sum: -1);

}