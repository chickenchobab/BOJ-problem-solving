#include <iostream>
#include <algorithm>

using namespace std;

int n;
int price[1001][4];
long long d[1001][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    
    price[0][1]=price[0][2]=price[0][3]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>price[i][j];
        }

        d[i][1]=min(d[i-1][2], d[i-1][3])+price[i][1];
        d[i][2]=min(d[i-1][3], d[i-1][1])+price[i][2];
        d[i][3]=min(d[i-1][1], d[i-1][2])+price[i][3];
    }

    cout<<min(d[n][1], min(d[n][2], d[n][3]));

    






}