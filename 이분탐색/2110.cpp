#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,c;
    long long max,min,mid,ans,v[MAX];
    cin>>n>>c;
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v,v+n);
    max=v[n-1]-v[0], min=1;

    ans=0;
    int cnt,idx;

    while(min<=max){
        cnt=1,idx=0;
        mid=(min+max)/2;
        
        for(int i=idx+1;i<n;i++){
            if(v[i]-v[idx]>=mid){
                cnt++; idx=i;
                //cout<<cnt<<"nd idx is "<<idx<<endl;
            }
        } 

        if(cnt<c) max=mid-1;   
        else{
            min=mid+1;
            if(ans<mid) ans=mid;
        }
    }

    cout<<ans;
}