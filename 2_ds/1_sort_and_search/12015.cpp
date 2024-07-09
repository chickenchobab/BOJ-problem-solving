#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

int n;
int arr[MAX];
vector<long long> d;

int find(int l, int r, int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]>=x) r=mid-1;
        else l=mid+1;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    for(int i=1;i<=n;i++){
        
        cin>>arr[i];
    }

    d.push_back(0);

    for(int i=1;i<=n;i++){
        if(arr[i]>d.back()) d.push_back(arr[i]);

    }

    long long m=0;
    for(int i=1;i<=n;i++){
        m=max(d[i],m);
    }

    cout<<m;

}