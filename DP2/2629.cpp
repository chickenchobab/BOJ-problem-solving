#include <iostream>
#include <algorithm>

using namespace std;

int n,m, w[31], o[8];
bool dp[40001];

int main(){
    //구슬의 무게에 추의 무게를 더하거나 빼서 0이 되나
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>w[i];
        dp[w[i]]=1;
    }
    cin>>m;
    for(int i=1;i<=m;i++) 
        cin>>o[i];

    sort(o+1, o+m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(o[j]-o[j-1]==w[i])
                
        }
    }

    for(int i=1;i<=m;i++){
        if(dp[o[i]]) cout<<"Y ";
        else cout<<"N ";
    }



    
}