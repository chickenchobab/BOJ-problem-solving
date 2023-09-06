#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

long long n,m,k,a,b,c;
long long arr[MAX], segtree[4*MAX];

long long init(int s, int e, int idx){
    if(s==e) return segtree[s];
    int mid=(s+e)/2;
    return segtree[idx]=init(s,mid,2*idx)+init(mid+1,e,2*idx+1);
}

long long sum(int s, int e, int l, int r, int idx){
    if(l<s && r>e) return 0;
    

}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }


}