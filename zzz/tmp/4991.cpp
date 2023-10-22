#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n,m,map[21][21];
typedef pair<int, int> p;
int di[]={1,-1,0,0}, dj[]={0,0,1,-1}, visited[21][21];

typedef tuple<int, int, int> edge;
vector<edge> v;
int set[12], done[12], cnt, sum, st;

void reset(){
    cnt=sum=0;
        fill(&set[1], &set[11], -1);
        fill(&done[1], &done[11], 0);
        v.clear();
}

int find(int x){
    if(set[x]<0) return x;
    return set[x]=find(set[x]);
}

void unite(int a, int b){
    a = find(a), b = find(b);
    if(set[a]<set[b]){
        set[b]=a;
    }
    else{
        if(set[a]==set[b])
            set[b]--;
        set[a]=b;
    }
}

void bfs(int i, int j){
    fill(&visited[1][1], &visited[n][m], 0);
    queue<p> q;
    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        p tmp = q.front();
        q.pop();
        i = tmp.first, j= tmp.second;
        for(int d=0; d<4; d++){
            int ni=i+di[d], nj=j+dj[d];
            if(ni<1 || nj<1 || ni>n || nj>m) continue;
            if(map[ni][nj]==-1) continue;
            if(visited[ni][nj]) continue;
            q.push({ni,nj});
            visited[ni][nj]=visited[i][j]+1;
            if(map[ni][nj]>cnt) {
                v.push_back({visited[i][j], cnt, map[ni][nj]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(1){
        cin>>m>>n;
        if(!m && !n) break;

        reset();

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char tmp;
                cin>>tmp;
                if(tmp == 'o' || tmp == '*') map[i][j]=++cnt;
                else if(tmp == 'x') map[i][j]=-1;
                else map[i][j]=0;
                if(tmp=='o') st=map[i][j];
            }      
        }

        cnt=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(map[i][j]==cnt){     //cnt번 칸의 모든 엣지 추가
                    bfs(i,j);
                    cnt++;
                }
            }
        }

        sort(v.begin(), v.end());
        // for(auto e: v){
        //     cout<<get<0>(e)<<' '<<get<1>(e)<<' '<<get<2>(e)<<endl;
        // }
        int a=0,b=0;
        for(auto e:v){
            a=get<1>(e);
            b=get<2>(e);
            if(find(a)==find(b)) continue;
            if(done[a]==2 || done[b]==2) continue;
            if(done[st]==1 && (a==st || b==st)) continue;
            
            unite(a,b);
            done[a]++; done[b]++;
            sum+=get<0>(e);
            //cout<<get<0>(e)<<' '<<get<1>(e)<<' '<<get<2>(e)<<endl;
        }

        for(int i=1;i<cnt;i++){
            if(set[find(i)]==-1) sum=-1;
        }
        if(cnt==2) sum=0;

        cout<<sum<<'\n';
        

    }
    
    return 0;

}