#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n,k; 
    cin>>n>>k;

    ll l=1,r=k,mid,cnt,num;
    while(l<=r){
        mid = (l+r)/2;
        cnt=0;
        for(int i=1;i<=n;i++){
           cnt+= min((mid)/i,n);
        }
        //cout<<"l:"<<l<<" r:"<<r<<' '<<cnt<<endl;
        if(cnt<k) {l=mid+1;}
        else {r=mid-1;num=mid;}
    }
    cout<<num; 


    
}