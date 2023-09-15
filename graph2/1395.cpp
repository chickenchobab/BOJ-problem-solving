#include <iostream>
#include <algorithm>

using namespace std;

int n,m,o,s,t;
int tree[400000];
bool lazy[400000];

void update_lazy(int node, int s, int e){
    if(lazy[node]){
        
        tree[node]=(e-s+1)-tree[node];
        if(s!=e){
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
        }
        lazy[node]=0;
    }
}

int sum(int node, int s, int e, int l, int r){
    update_lazy(node, s, e);
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return tree[node];
    
    int mid=(s+e)/2;
    return sum(2*node, s,mid,l,r)+sum(2*node+1, mid+1, e, l, r);
}

void update_range(int node, int s, int e, int l, int r){
    update_lazy(node, s,e);
    if(r<s || e<l) return;
    
    if(l<=s && e<=r){
        tree[node]=(e-s+1)-tree[node];
        if(s!=e){
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
        }
        return;
    }

    int mid=(s+e)/2;
    update_range(2*node, s, mid, l, r);
    update_range(2*node+1, mid+1, e, l, r);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
        cin>>o>>s>>t;
        if(!o){
            update_range(1,1,n,min(s,t),max(s,t));
        }
        else{
            cout<<sum(1,1,n,min(s,t),max(s,t))<<'\n';
        }
        //show();
    }
}

