#include <iostream>
#include <algorithm>
#define div 1000000000

using namespace std;

int n,k;
long long dp[201][201];

long long sum(int a, int b){
    if(dp[a][b]) return dp[a][b];
    if(a==0) return dp[a][b]=1;
    if(b==1) return dp[a][b]=1;

    long long s=0;
    for(int i=0;i<=a-1;i++){
        s=(s+sum(i,1)+sum(a-i,b-1))%div;
    }
    return dp[a][b]=s;
}

int main(){
    cin>>n>>k;
    fill(&dp[0][0], &dp[n][k],0);
    cout<<sum(n,k);


}