#include <iostream>

using namespace std;

int n;
int node[100001], edge[100001];

long long cur, oil, sum;

int main(){
    cin>>n;
    for(int i=1;i<=n-1;i++) cin>>edge[i];
    for(int i=1;i<=n;i++) cin>>node[i];
    
    cur=node[1];
    for(int i=1; i<n; i++){
        if(oil<edge[i]) {
            sum=sum+(edge[i]-oil)*cur;
            oil=edge[i];
        }
        if(cur>node[i+1]) cur=node[i+1];
        oil-=edge[i];
    }
    cout<<sum;
}