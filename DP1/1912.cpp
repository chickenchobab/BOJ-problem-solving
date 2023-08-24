#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,tmp,d[100001];
    long long m=-100000000;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(!i) d[i]=tmp;
        else d[i]=max(d[i-1]+tmp, tmp);
        if (m<d[i]) m=d[i];
    }

    cout<<m;
    
}