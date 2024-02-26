#include <iostream>
#define MAX 1000001

using namespace std;

int n,m,k;
long long arr[MAX], tree[4*MAX], lazy[4*MAX];
long long a,b,c,d;

long long init(int node, int s, int e){
    if(s==e) return tree[node]=arr[s];
    int mid=(s+e)/2;
    return tree[node]=init(2*node, s, mid)+init(2*node+1, mid+1, e);
}

long long sum(int node, int s, int e, int l, int r){
    if(r<s || l>e) return 0;
    if(l<=s && e<=r) return tree[node];
    int mid=(s+e)/2;
    return sum(2*node, s, mid, l, r)+sum(2*node+1, mid+1, e, l, r);
}

void update_lazy(int node, int s, int e){
    
    if(lazy[node]!=0){
        tree[node]+=(e-s+1)*lazy[node];
        if(s!=e){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update_range(int node, int s, int e, int l, int r, long long gap){
    update_lazy(node, s, e);
    if(r<s || l>e) return;
    if(l<=s && e<=r){
        tree[node]+=(e-s+1)*gap;
        if(s!=e){
            lazy[2*node]+=gap;
            lazy[2*node+1]+=gap;
        }
        return;
    }
    update_range(node*2, s, (s+e)/2, l, r, gap);
    update_range(node*2+1, (s+e)/2+1, e, l, r, gap);
    tree[node] = tree[2*node]+tree[2*node+1];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    init(1,1,n);
    int t=m+k;
    while(t--){
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            update_range(1,1,n,b,c,d);
        }
        else{
            cin>>b>>c;
            update_range(1,1,n,b,c,0);
            cout<<sum(1,1,n,b,c)<<'\n';
        }
    }
}