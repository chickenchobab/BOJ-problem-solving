#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstdio>

using namespace std;

int n,m,map[1001][1001];
queue<pair<int,int>> q;

void bfs(){
    

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