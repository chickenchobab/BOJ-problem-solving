#include <iostream>
#include <algorithm>

using namespace std;

int t,n;


int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int file[501], sum[501];
        int dp[501][501];
        
        fill(&dp[0][0],&dp[500][500],1000000000);
        for(int i=1;i<=n;i++){
            cin>>file[i];
            sum[i]=sum[i-1]+=file[i];
        }

        for(int i=1;i<=n;i++){
            for(int j=1;i+j-1<=n;j++){
                if(i+j-1==1)
                    dp[i][i+j-1]=0;
                else{
                    for(int k=j; k<i+j-1; k++){
                        dp[j][j+i-1]=min(dp[j][j+i-1], )
                    }
                }
            }
        }

        cout<<dp[1][c];
    }
}