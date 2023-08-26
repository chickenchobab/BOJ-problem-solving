#include <iostream>
#include <algorithm>
#define MAX 1000000000

using namespace std;

int n;
long long d[10][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    
    
    fill(&d[0][0],&d[9][100],0);
        
    for(int i=0;i<=9;i++)
        d[i][1]=(i? 1: 0);
    
    for(int i=2;i<=n;i++){
        d[0][i]+=d[1][i-1]%MAX;
        d[9][i]+=d[8][i-1]%MAX;
        for(int j=1;j<=8;j++){
            d[j][i]+=(d[j-1][i-1]%MAX+d[j+1][i-1]%MAX);
        }
    }

    long long sum=0;
    for(int i=0;i<=9;i++){
        sum+=(d[i][n]%MAX);
    }

    cout<<sum%MAX;
}