#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> point;
typedef tuple<int, int, int> edge;

int n,m,sum,idx,cnt;
int map[51][51];
int di[]={0,0,1,-1}, dj[]={1,-1,0,0};
int v[252];
vector<edge> e;

int find(int x){
    if(v[x]<=0) return x;
    return (v[x]=find(v[x]));
}

void unite(int a, int b){
    int c1=find(a);
    int c2=find(b);
    if(v[c1]<v[c2]){
        v[c2]=c1;
    }
    else{
        if(v[c1]==v[c2])
            v[c2]--;
        v[c1]=c2;
    }
}


void bfs(int si, int sj){
    
    queue<point> q;
    int visited[51][51];
    fill(&visited[0][0], &visited[50][50], 0);

    q.push({si,sj});
    visited[si][sj]=1;

    while(!q.empty()){
        point u=q.front();
        q.pop();
        int i=u.first, j=u.second;
        for(int k=0;k<4;k++){
            int ni=i+di[k], nj=j+dj[k];
            if(ni>n || nj>n || ni<1 || nj<1) continue;
            if(visited[ni][nj] || map[ni][nj]==-1) continue;
            q.push({ni,nj});
            visited[ni][nj]=visited[i][j]+1;
            if(map[ni][nj]) {
                cnt++;
                //cout<<ni<<' '<<nj<<endl;
                e.push_back({visited[ni][nj]-1, map[si][sj], map[ni][nj]});
            }
        }
    }
    map[si][sj]=0;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    cin.ignore();

    string str;
    int si,sj;
    for(int i=1;i<=n;i++){
        getline(cin, str);
        for(int j=1;j<=n;j++){
            if(str[j-1]=='1')   
                map[i][j]=-1;
            else if(str[j-1]=='0')
                map[i][j]=0;
            else if(str[j-1]=='S' || str[j-1]=='K')
                map[i][j]=++idx;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]>0) bfs(i,j);
        }
    }

    sort(e.begin(), e.end());
    for(edge tmp:e){
        int a=get<1>(tmp);
        int b=get<2>(tmp);
        int c=get<0>(tmp);
        if(find(a)==find(b)) continue;
        unite(a,b);
        sum+=c;
    }
    
    cout<<(cnt==(m+1)*m/2? sum:-1);
}