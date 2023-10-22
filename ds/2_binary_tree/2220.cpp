#include <iostream>

using namespace std;

int n,s;
int heap[100001];

void push(int x){
    int i;
    heap[++s]=x;
    if(s==1) return;

    swap(heap[s],heap[s-1]);
    
    for(i=s-1; heap[i/2]<x && i>1; i/=2){
        heap[i]=heap[i/2];
    }
    heap[i]=x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        push(i);
    }
    for(int i=1;i<=n;i++){
        cout<<heap[i]<<' ';
    }
    
}