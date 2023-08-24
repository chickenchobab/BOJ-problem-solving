#include <iostream>
#define MAX 1000000

using namespace std;

int n;
long long m;
long long tree[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long tmp,max=0,min=1,sum,result=0;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>tree[i];
        max=(max>tree[i]? max: tree[i]);
    }

    while(min<=max){
        sum=0;
        long long mid=(max+min)/2;

        for(int i=0;i<n;i++){
            if(tree[i]<=mid) continue;
            sum+=(tree[i]-mid);

        }

        if(sum<m)   max=mid-1;
        else {min=mid+1;  result=(mid);}

    }
    cout<<result;

}