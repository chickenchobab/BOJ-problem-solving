#include <iostream>
#include <algorithm>

using namespace std;

int n;
int score[10001];
long long dp[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>score[i];
    }
    dp[1]=score[1];
    dp[2]=score[1]+score[2];

    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-2], dp[i-3]+score[i-1])+score[i];
        dp[i]=max(dp[i-1],dp[i]);
    }

    sort(dp+1, dp+n+1);
    cout<<dp[n];
}