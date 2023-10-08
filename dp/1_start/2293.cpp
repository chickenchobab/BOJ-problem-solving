#include <iostream>
#include <algorithm>
#define MAX 10001

using namespace std;

int n,k;
int coin[101];
long long d[MAX];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }
    sort(coin+1, coin+n+1);

    for(int i=1;i<=n;i++){
        for(int j=coin[i];j<=k;j++){
            d[j]+=d[j-coin[i]];
        }
        for(int j=coin[i];j<=k;j++){
            if(!(j%coin[i])) d[j]++;
        }
        
        // for(int j=1;j<=k;j++){
        //     cout<<d[j]<<' ';
        // }
        // cout<<endl;
    }

    cout<<d[k];

    

    
}