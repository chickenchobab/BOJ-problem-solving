#include <iostream>
#include <algorithm>
#define MAX 10001

using namespace std;

int n,k;
int coin[101];
int d[MAX];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }
    sort(coin+1, coin+n+1);

    for(int i=1;i<=k;i++){
        d[i]=MAX;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=coin[i];j<=k;j++){
            if(!(j%coin[i])) 
                d[j]=j/coin[i];
            d[j]=min(d[j], d[j-coin[i]]+1);
        }
    }

    cout<<(d[k]<MAX? d[k]: -1);
}