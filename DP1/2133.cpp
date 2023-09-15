#include <iostream>

using namespace std;

int n;
long long d[31];

int main(){
    cin>>n;
    d[2]=3;
    for(int i=4;i<=n;i++){
        d[i]+=d[i-2]*d[2];
        for(int j=4;j<=i;j+=2)
            d[i]+=d[i-j]*2;
    }
    cout<<d[n];

}