#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long k,n,cnt,max=0,min=1,mid,result=0,arr[10000];
    cin>>k>>n;

    for(int i=0;i<k;i++){
        cin>>arr[i];
        if(max<arr[i]) max=arr[i];
    }

    while(min<=max){
        cnt=0;
        mid=(max+min)/2;
        //cout<<mid<<' ';

        for(int i=0;i<k;i++)
            cnt+=arr[i]/mid;

        if(cnt<n) {
             max=mid-1;
        }
        else{
            min=mid+1;
            if(result<mid) result=mid;
        }
    }

    cout<<result;
    
}