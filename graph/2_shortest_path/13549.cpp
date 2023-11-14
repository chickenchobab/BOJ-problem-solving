#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100000

using namespace std;

int n,k;
int dp[100001];

void bfs(){
    queue<int> q;
    q.push(n);
    dp[n]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        //dp조건체크 : 방문체크
        if(u+1<=100000 && dp[u+1]>dp[u]+1){
            dp[u+1]=dp[u]+1;
            q.push(u+1);
        }
        if(u-1>=0 && dp[u-1]>dp[u]+1){
            dp[u-1]=dp[u]+1;
            q.push(u-1);
        }
        if(2*u<=100000 && dp[2*u]>dp[u]){
            dp[2*u]=dp[u];
            q.push(2*u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<=100000;i++) dp[i]=MAX;
    bfs();
    cout<<dp[k];
}