#include <iostream>
#include <algorithm>

using namespace std;

int n;
int score[301];
long long dp[301]; // i칸을 밟는 경우의 최댓값

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>score[i];
    }

    dp[1]=score[1];
    dp[2]=score[1]+score[2];
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-2],dp[i-3]+score[i-1])+score[i];
    }

    cout<<dp[n];

    return 0;
    
}