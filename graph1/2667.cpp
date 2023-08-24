#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

vector<int> cnt;
int n,c,map[26][26];

// void dfs(int i, int j){
//     if(map[i][j]!=0) return;
//     if(i==0 || j==0 || i==n+1 || j==n+1) return;

//     map[i][j]=1; c++;

//     dfs(i+1,j);
//     dfs(i-1,j);
//     dfs(i,j+1);
//     dfs(i,j-1);
// }

void bfs(int i, int j){
    if(map[i][j]!=0) return;

    queue<pair<int,int>> q;
    int di[]={0,0,1,-1};
    int dj[]={1,-1,0,0};

    q.push({i,j}); map[i][j]=1; c++;

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>0 && ni<=n && nj>0 && nj<=n){
                if(!map[ni][nj]) {
                    q.push({ni,nj}); map[ni][nj]=1; c++;
                }
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n; cin.ignore();

    for(int i=1;i<=n;i++){
        string str;
        getline(cin,str);
        for(int j=1;j<=n;j++){
            int tmp=str[j-1]-'0';
            
            if(!tmp) map[i][j]=-1;
            else map[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c=0;
            //dfs(i,j);
            bfs(i,j);
            if(c) cnt.push_back(c);
        } 
    }

    sort(cnt.begin(), cnt.end());
    cout<<cnt.size()<<'\n';
    for(int i=0;i<cnt.size();i++){
        cout<<cnt[i]<<'\n';
    }

}